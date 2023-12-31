#include "Solution.h"


void Solution::directProblem(){
    std::pair<std::vector<StateVector>,std::vector<ModelVector>> result =  integrator.RK4(s55.getInitialVector());
    s55.setHistory(result.first);
    s55.setModelData(result.second);
}


void Solution::inverseProblem(){
    int numRows = 26;
    Matrix R = Matrix(numRows*2, 1);
    Matrix A = Matrix(numRows*2, 6);
    double W[numRows * 2];
    double deltaRa = 0;
    double deltaDecl = 0;

    double RaSum = 0;
    double DeclSum = 0;

    for(int i = 0; i < this->s55.getRealData().size(); i++){
        this->gaussNewton.calculate_dg_dx(this->s55.getModelData().at(i));
        this->gaussNewton.calculate_dr_db(this->s55.getModelData().at(i));

        deltaRa = this->s55.getRealData().at(i).getEquatorial().getRa() - this->s55.getModelData().at(i).getEquatorial().getRa();
        deltaDecl = this->s55.getRealData().at(i).getEquatorial().getDecl() - this->s55.getModelData().at(i).getEquatorial().getDecl();

        RaSum += deltaRa * deltaRa;
        DeclSum += deltaDecl * deltaDecl;
        for(int j = 0; j < 6; j++){
            A.setElem(this->s55.getModelData().at(i).get_dr_db().getElem(0, j), 2 * i, j);
            A.setElem(this->s55.getModelData().at(i).get_dr_db().getElem(1, j), 2 * i + 1, j);
        }

        R.setElem(deltaRa, 2 * i, 0);
        R.setElem(deltaDecl, 2 * i + 1, 0);

        double acc = 1e4;
        int lastDigit = int(deltaRa * acc * 10) % 10;
        double Wra = lastDigit != 0 ? (2 * lastDigit) / (acc * 10) : (2 * (lastDigit + 1)) / (acc * 10);
        lastDigit = int(deltaDecl * acc * 10) % 10;
        double Wdec = lastDigit != 0 ? (2 * lastDigit) / (acc * 10) : (2 * (lastDigit + 1)) / (acc * 10);
        W[2 * i] = 1.0 / (Wra * Wra);
        W[2 * i + 1] = 1.0 / (Wdec * Wdec);
  
    }
    long double Ra_avg = RaSum / numRows;
    long double Decl_avg = DeclSum / numRows;

    long double devRa = 0, devDecl = 0;

    for(int i = 0; i < numRows; i++){
        auto Ra_i = R.getElem(2*i, 0);
        auto Decl_i = R.getElem(2 * i + 1, 0);
        devRa += pow(Ra_i - Ra_avg, 2);
        devDecl += pow(Decl_i - Decl_avg, 2);
    }

    devRa /= numRows;
    devDecl /= numRows;

    this->sumOfSquares.first = sqrtl(devRa);
    this->sumOfSquares.second = sqrtl(devDecl);
    this->s55.setInitialState(this->gaussNewton.GaussNewtonAlg(this->s55.getInitialVector(), &A, &R, W));

}

void Solution::writeDirectProblemResult(){
    std::fstream xCoordsFile("graph/dataForGraph/x.txt");
    std::ofstream yCoordsFile("graph/dataForGraph/y.txt");
    std::ofstream zCoordsFile("graph/dataForGraph/z.txt");
    std::ofstream raCoordsFile("graph/dataForGraph/ra.txt");
    std::fstream declCoordsFile("graph/dataForGraph/decl.txt");
    std::fstream modelData("dataIO/modelData.txt");

    if(!xCoordsFile.is_open()){
        std::cerr << "Failed to open file: " << "/graph/dataForGraph/x.txt" << std::endl;
    }
    if(!yCoordsFile.is_open()){
        std::cerr << "Failed to open file: " << "/graph/dataForGraph/y.txt" << std::endl;
    }
    if(!zCoordsFile.is_open()){
        std::cerr << "Failed to open file: " << "/graph/dataForGraph/z.txt" << std::endl;
    }
    if(!raCoordsFile.is_open()){
        std::cerr << "Failed to open file: " << "/graph/dataForGraph/ra.txt" << std::endl;
    }
    if(!declCoordsFile.is_open()){
        std::cerr << "Failed to open file: " << "/graph/dataForGraph/decl.txt" << std::endl;
    }
    if(!modelData.is_open()){
        std::cerr << "Failed to open file: " << "dataIO/modelData.txt" << std::endl;
    }

    for(StateVector state: s55.getHistory()){
        xCoordsFile << state.getCartesianCoords().getX() << std::endl;
        yCoordsFile << state.getCartesianCoords().getY() << std::endl;
        zCoordsFile << state.getCartesianCoords().getZ() << std::endl;

        raCoordsFile << state.getEquatorialCoords().getRa() << std::endl;
        declCoordsFile << state.getEquatorialCoords().getDecl() << std::endl;
    }

    for(ModelVector state: s55.getModelData()){
        modelData << std::setprecision(7) << state.getDate().getYear() << " " 
        <<std::setprecision(6)<< state.getEquatorial().getRa() << " " 
        <<std::setprecision(6)<< state.getEquatorial().getDecl() << std::endl;
    }

    if(xCoordsFile.is_open()){
        xCoordsFile.close();
    }

    if(yCoordsFile.is_open()){
        yCoordsFile.close();
    }

    if(zCoordsFile.is_open()){
        zCoordsFile.close();
    }

    if(raCoordsFile.is_open()){
        raCoordsFile.close();
    }

    if(declCoordsFile.is_open()){
        declCoordsFile.close();
    } 
    if(!modelData.is_open()){
        modelData.close();
    }
}

void Solution::readObservatoryData(){
    std::ifstream inputFile("dataIO/observatoryData.txt");
    std::vector<ModelVector> realData;
    if(inputFile.is_open()){
        std::string line;
        while(std::getline(inputFile, line)){
            std::istringstream iss(line);
            ModelVector readlVec;
            Date date;
            EquatorialCoords eCoords;
            double DateInYear;
            double Ra;
            double Decl;
            if (iss >> DateInYear >> Ra >> Decl){
                date.setYear(DateInYear - 2004.511);
                eCoords.setRa(Ra);
                eCoords.setDecl(Decl);
                readlVec.setEquatorialCoords(eCoords);
                readlVec.setDate(date);
                realData.push_back(readlVec);
            }
        }
        s55.setRealData(realData);
        inputFile.close();
    } 
    else{
        std::cout << "Error open file: dataIO/observatoryData.txt" << std::endl; 
    }
}

void Solution::clear(){
    this->integrator.reset();
    this->s55.clear();
}

void Solution::generalSolution(){
    std::ofstream result("result.txt");
    this->readObservatoryData();
    int iter = 0;

    while(true){
        StateVector vectorInitial = s55.getInitialVector();
        std::cout << "Iteration: " << iter + 1 << "\n";
        result << "Iteration: " << iter + 1 << "\n";
        
        std::cout << "Current x0 (before GN): " << std::setprecision(18) << s55.getInitialVector().getCartesianCoords().getX() << " " 
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getY() << " "
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getZ() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVx() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVy() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVz() << std::endl;

        result << "Current x0 (before GN): " << std::setprecision(18) << s55.getInitialVector().getCartesianCoords().getX() << " " 
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getY() << " "
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getZ() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVx() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVy() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVz() << std::endl;

        this->directProblem();
        this->inverseProblem();
        std::cout << "Ra sum squares = " << sumOfSquares.first << "\n";
        std::cout << "Decl sum of squares = " << sumOfSquares.second << "\n";
        std::cout << "Current x0 (after GN): " << std::setprecision(18) << s55.getInitialVector().getCartesianCoords().getX() << " " 
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getY() << " "
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getZ() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVx() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVy() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVz() << std::endl;

        result << "Ra sum squares = " << sumOfSquares.first << "\n";
        result << "Decl sum of squares = " << sumOfSquares.second << "\n";
        result << "Current x0 (after GN): " << std::setprecision(18) << s55.getInitialVector().getCartesianCoords().getX() << " " 
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getY() << " "
        << std::setprecision(18)<< s55.getInitialVector().getCartesianCoords().getZ() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVx() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVy() << " "
        << std::setprecision(9)<< s55.getInitialVector().getVelocity().getVz() << std::endl;

        iter++;
        this->clear();
    }
}