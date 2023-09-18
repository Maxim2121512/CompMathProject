import matplotlib.pyplot as plt
import numpy as np
import math

file_paths = ["dataForGraph/x.txt", "dataForGraph/y.txt", "dataForGraph/z.txt",
              "dataForGraph/ra.txt", "dataForGraph/decl.txt", "../dataIO/modelData.txt"]


dataX = np.loadtxt(file_paths[0])
dataY = np.loadtxt(file_paths[1])
dataZ = np.loadtxt(file_paths[2])

ra = np.loadtxt(file_paths[3])
decl = np.loadtxt(file_paths[4])



def S55_3d_Cartesian():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(dataX, dataY, dataZ)
    ax.set_xlabel('x (km)')
    ax.set_ylabel('y (km)')
    ax.set_zlabel('z (km)')
    ax.set_title('S55_3d_Cartesian_model')
    plt.show()


def S55_Equatorial():
    fig, ax = plt.subplots()
    ax.plot(ra , decl)
    ax.set_xlabel("Ra (arcsec) ")
    ax.set_ylabel("Decl (arcsec)")
    ax.set_title("S55_Equatorial")
    ax.invert_xaxis();
    plt.show()

S55_Equatorial()

for path in file_paths:
    with open(path, "w") as file:
        file.truncate(0);
