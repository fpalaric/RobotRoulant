import numpy as np
from matplotlib import pyplot as plt

plt.rcParams["figure.figsize"] = [7.50, 7.50]
plt.rcParams["figure.autolayout"] = True

# Point x,y, destination du robot, à faire varier
x = 2
y = 1

a = (pow(x,2)+pow(y,2))/(2*y) #rayon du cercle passant par l'origine A et la destination B
angleRoue = - np.arctan(a/0.215) + 3.14/2 # angle de la roue pour arriver à la destination
angleRoueDeg = (angleRoue *180) / (3.14/2) # convertion en deg
distanceAPArcourir = (3.14/2 - np.sin((a-y)/(np.sqrt(pow(x,2)+pow((a-y),2))))) * a #distance à parcour pour arriver à la destination

circle1 = plt.Circle((0, a), a, color='b', fill=False, clip_on=False) #ercle passant par l'origine A et la destination B

#représentation graphique des résultats
ax = plt.gca()
ax.cla() # clear things for fresh plot
ax.set_xlim((-a - a/10, a + a/10))
ax.set_ylim((-a/10, 2 * a + a/10))

ax.text(-a/20,-a/20,"A(0,0)")
ax.scatter(x,y,marker="+", color = "red")
ax.add_patch(circle1)
ax.plot([0,0],[0,a], marker="o")
ax.text(x+a/20,y,"B("+str(x)+","+str(y)+")")
ax.text(-a/5, a/2, "a="+ str(a))
ax.text(-a/2,a+a/5,"Distance a parcourir =" + str(float(distanceAPArcourir))+"m")
ax.text(-a/2,a+a/10,"angle roue =" + str(angleRoueDeg)+"°")
plt.show()
