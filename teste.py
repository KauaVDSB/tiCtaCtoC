# Programa para o oscilador harmonico com rotacao



from visual import * # pacote para visualizacao da animacao

from math import * # pacote matematico

from visual.graph import * # pacote de visualizacao dos graficos



# CENA 1 - informacoes da tela de animacao



scene.range = (10 ,10 ,10) # zoom em relacao ao centro da tela

scene.center = (0 ,0 ,0)# centro da tela

scene.width = 700 # comprimento

scene.height = 400 # altura

scene.background = (1 ,1 ,1)#cor de fundo

scene.title = "Sistema Massa - Mola com Rotacao"



# CENA 2 - informacoes da tela do grafico

graph1 = gdisplay ( width =400 , height =300 ,

title ='Graficos para o movimento',

xtitle ='t(s)', ytitle ='', xmax =10. , xmin =0. , ymax =3 , ymin = -3 ,

foreground = color . black , background = color . white )



# Funcoes - informacoes para o grafico do movimento

# grafico para a posicao

funcao1 = gdots ( gdisplay = graph1 , color = color . red )

# grafico para a velocidade

funcao2 = gdots ( gdisplay = graph1 , color = color . black )

# grafico para a aceleracao

funcao3 = gdots ( gdisplay = graph1 , color = color . blue )



# Figuras



piso = box ( pos =(0.5 , -2.2 , -2.5) , size =(15 ,0.4 ,6))

paredeE = box ( pos =( -6.6 ,1 , -2.5) , size =(0.4 ,6 ,6))

mola = helix ( pos =( -6.5 ,0 , -2.5) , radius =0.8 , coils =10 , thickness =0.1 ,

color = color . blue )

disco = cylinder ( pos =(0 ,0 , -4.5) , radius =2 , color = color . orange ,

material = materials . rough , axis =(0 ,0 ,4) )

seta = arrow ( pos =(0 ,0 , -0.5) , axis = (1 ,0 ,0) , color = color . red )

eixo = cylinder ( pos = (0 ,0 , -5) , radius =0.2 , axis = (0 ,0 ,5) ,

color = color . blue )

suporte1 = box ( pos =( -1 ,0 , -0.2) , size =(2.5 ,0.4 ,0.2) ) # prender na parte frontal do eixo do disco

suporte2 = box ( pos =( -1 ,0 , -4.8), size =(2.5 ,0.4 ,0.2) ) # prender na parte traseira do eixo do disco

suporte3 = box ( pos =( -2.3 ,0 , -2.5) , size =(0.2 ,0.4 ,4.8) ) # prender na mola



# Definindo as grandezas e condicoes iniciais



dt = 0.01 # incremento de tempo em segundos (s)

t = 0 # tempo inicial em segundos (s)

R = 0.1 # raio do disco em metros (m)

M = 0.4 # massa do disco em quilogramas (Kg)

I = 0.5* M*R**2 # Momento de inercia do disco (Kg*m ^2)

k = 4 # contantes eleastica (N/m)

v = 0 # velocidade inicial (m/s)

x = 2 # posicao inicial em metros (m)

w = 0 # velocidade angular



# Contrucao da animacao



while (1==1) :
  rate (250)
  a = ( -2* k /3* M)* disco . pos .x # equacao de aceleracao 
  v += a* dt # equacao de velocidade
  x += v* dt # equacao de posicao
  w = w + a* dt /R # equacao de velocidadeangular
  mola . axis = suporte3 . pos - paredeE . pos + (0 ,1 ,0) # movimento da mola
  disco . pos . x = x # movimento do disco
  t = t + dt # evolucao temporal
  eixo . pos .x = disco . pos .x
  suporte1 . pos .x = disco . pos .x - 1
  suporte2 . pos .x = disco . pos .x - 1
  suporte3 . pos .x = disco . pos .x - 2.3
  disco . rotate ( axis =(0 ,0 ,0.5) , angle = -w * dt )
  seta . pos = disco . pos + (0 ,0 ,4)
  seta . rotate ( axis =(0 ,0 ,1) , angle = -w* dt )
  
  
  if abs ( disco .x ) >= mola . axis :
    disco . rotate ( axis =(0 ,0 ,0.5) , angle = w*dt )
    
  if t < 10:
    funcao1 . plot ( pos =(t ,x) ) # plot posicao em funcao do tempo
    funcao2 . plot ( pos =(t ,v) ) # plot velocidade em funcao do tempo
    funcao3 . plot ( pos =(t ,a) ) # plot aceleracao em funcao do tempo