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



ra_dots = [0.0549, 0.0711, 0.0707, 0.0731, 0.0749, 0.0790, 0.0731, 0.0835, 0.0797, 0.0784, 0.0659, 0.0641, 0.0711, 0.0692, 0.0678, 0.0620, -0.0017, -0.0257, -0.0305, -0.0390, -0.0620, -0.0523, -0.0492, -0.0345, -0.0134, 0.0239];
decl_dots = [-0.1552, -0.1536, -0.1437, -0.1199, -0.1220, -0.1180, -0.1169, -0.0883, -0.0763, -0.0635, -0.0346, -0.0338, -0.0309, -0.0167, -0.0144, -0.0058, 0.0358, 0.0291, 0.0243, 0.0378, -0.0453, -0.0404, -0.1080, -0.1180, -0.1380, -0.1678];
ra2_dots = [0.056463, 0.056567, 0.071523, 0.091617, 0.092887, 0.094717, 0.095626, 0.10001, 0.10048, 0.10217, 0.10542, 0.10548, 0.1055, 0.10526, 0.10477, 0.10418, 0.096545, 0.092892, 0.090157, 0.086818, 0.045649, 0.04462, -0.053258, -0.058098, -0.038755, 0.010395]
decl2_dots = [-0.15577, -0.15573, -0.14681, -0.1242, -0.12204, -0.11866, -0.11685, -0.10621, -0.10482, -0.099053, -0.076831, -0.075004, -0.072474, -0.065574, -0.060166, -0.055858, -0.029337, -0.021692, -0.016821, -0.011586, 0.022413, 0.022819, -0.02206, -0.0854, -0.12691, -0.15985]

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
    plt.scatter(ra_dots, decl_dots, color = 'blue', marker='o', label='Наблюдательные данные');
    plt.scatter(ra2_dots, decl2_dots, color = 'red', marker='o', label='Смоделированные данные');
    plt.show()


S55_Equatorial()

for path in file_paths:
    with open(path, "w") as file:
        file.truncate(0);
