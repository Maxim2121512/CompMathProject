import matplotlib.pyplot as plt
import numpy as np

dataX = np.loadtxt("dataForGraph/x.txt")
dataY = np.loadtxt("dataForGraph/y.txt")
dataZ = np.loadtxt("dataForGraph/z.txt")

ra = np.loadtxt("dataForGraph/ra.txt")
decl = np.loadtxt("dataForGraph/decl.txt")

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
    plt.show()


S55_3d_Cartesian()
S55_Equatorial()