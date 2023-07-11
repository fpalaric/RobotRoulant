Le projet est d'emmener un robot d'un point A à un point B grâce à des combinaisons de courbe et de ligne droite.

Pour que le robot effectue une courbe comme ci-dessous :

![croquis](https://github.com/fpalaric/RobotRoulant/assets/36034881/342cbd68-2b4f-46f5-9b8f-37dc5af9ad8f)


Après calcul : 
Distance a = (x²+y²)/2*y

Angle de la roue = - atan(a/L) + pi/2 avec L empattement = 0.215m

Distance à parcourir = ((pi/2 - sin((a-y)/(sqrt(x²+(a-y)²))) * a

Représentation des calculs avec quelques exemples :

![image](https://github.com/fpalaric/RobotRoulant/assets/36034881/419d4b4a-9475-4718-a995-409c77800c21)

![image](https://github.com/fpalaric/RobotRoulant/assets/36034881/0a75e4d4-2af1-4bdc-b51c-b34b7c92ec9a)

![image](https://github.com/fpalaric/RobotRoulant/assets/36034881/15476558-2578-49e2-a3cf-b919f0bfda8d)


.ino en cours de recherche
