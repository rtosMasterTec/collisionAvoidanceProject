import pygame
import time
import sys
#import xml.dom.minidom 

#data = \
#"""\
#<bot1>
#<time>
#<time>0</time>
#<speed>5</speed>
#<x_location>30 </x_location>
#<y_location>30 </y_location>
#</time>
#<time>
#<time>1</time>
#<speed>5</speed>
#<x_location>40 </x_location>
#<y_location>40 </y_location>
#</time>
#
#</bot1>
#"""
#
#
#

obstacles = []
dynamicBotMap={}
scale = 6

def vectorLoad(fname):
   file = open(fname)
   lines = (line.rstrip() for line in file) 
   lines = list(line for line in lines if line) #remove blanks
   lines = list(line for line in lines if line[0] != "#") #remove comments
   for line in lines:
      contents = "x y velocidad direccion n o s e".split()

      line = line.split()
      bot = line.pop(0)
      d = dict( zip( contents, line))
      for content in d.iterkeys():
         if content == "direccion":
            continue
         d[content] = int(d[content])
         if bot not in dynamicBotMap:
# each bot label contains a list of time related info
            dynamicBotMap[bot] = [] 
         dynamicBotMap[bot].append( d )

def mapLoad(screen):
   """This opens a file given by the console input"""
   file = open(sys.argv[1])
   lines = (line.rstrip() for line in file) 
   lines = list(line for line in lines if line) #remove blanks
   lines = list(line for line in lines if line[0] != "#") #remove comments
   for line in lines:
      contents = "xi yi xf yf".split()
      line = line.split()
      del line[0]
      lineint =  map(int, line) 
      d = dict(zip( contents , lineint ))
      obstacles.append(d);
   for object in obstacles:
      xi= object["xi"]
      yi = object["yi"]
      dx = object["xf"] - object["xi"] +1
      dy = object["yf"] - object["yi"] +1
      xi= xi*scale
      yi= yi*scale
      dx = dx*scale
      dy = dy*scale
      pygame.draw.rect(screen, (255,255,255), pygame.Rect(xi,yi,dx,dy))

def simulation():
   pygame.init()
   screen = pygame.display.set_mode((800, 800))
   mapLoad(screen)
   vectorLoad(sys.argv[2])
   vectorLoad(sys.argv[3])

   done = False
   x = 30
   y = 30
   while not done:
      for event in pygame.event.get():
         if event.type == pygame.QUIT:
            done = True
      time.sleep(0.5)
#      pygame.draw.rect(screen, (0, 0, 0), pygame.Rect(x, y, scale,scale ))
#      pygame.draw.rect(screen, (0, 128, 0), pygame.Rect(x, y, scale/2,scale/2 ))
#      x+=scale;
#      y+=scale;
#      pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(x, y, scale, scale))
#      pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(50, 100, scale, scale))
#      pygame.display.flip()
      #print dynamicBotMap
      screen.fill((0,0,0))
      mapLoad(screen)
      for t in range(len(dynamicBotMap["R1"])):
         print "t = %d" % t
         for bot in dynamicBotMap.iterkeys():

            x = dynamicBotMap[bot][t]["x"]
            y = dynamicBotMap[bot][t]["y"]
            if(bot == "R0"):
               color = (255, 0,0)
            else:
               color = (0, 255,0)
            pygame.draw.rect(screen, color, pygame.Rect(x*scale, y*scale, scale, scale))
         pygame.display.flip()

         # erase last position
         #time.sleep(0.5)
         for bot in dynamicBotMap.iterkeys():
            #print dynamicBotMap[bot]
            x = dynamicBotMap[bot][t]["x"]
            y = dynamicBotMap[bot][t]["y"]
            color = (0, 0,0)
            pygame.draw.rect(screen, color, pygame.Rect(x*scale, y*scale, scale, scale))
         #give a mark of last position
         for bot in dynamicBotMap.iterkeys():
            #print dynamicBotMap[bot]
            x = dynamicBotMap[bot][t]["x"]
            y = dynamicBotMap[bot][t]["y"]
            if(bot == "R0"):
               color = (255, 0,0)
            else:
               color = (0, 255,0)
            pygame.draw.rect(screen, color, pygame.Rect(x*scale, y*scale, 2, 2))

if __name__ == "__main__":
   #mapLoad()
   simulation()
