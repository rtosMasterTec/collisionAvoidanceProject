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
scale = 6

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
      dx = object["xf"] - object["xi"]
      dy = object["yf"] - object["yi"]
      xi= xi*scale
      yi= yi*scale
      dx = dx*scale
      dy = dy*scale
      pygame.draw.rect(screen, (255,0,0), pygame.Rect(xi,yi,dx,dy))

def simulation():
   pygame.init()
   screen = pygame.display.set_mode((800, 800))
   mapLoad(screen);

   done = False
   x = 30
   y = 30
   while not done:
      for event in pygame.event.get():
         if event.type == pygame.QUIT:
            done = True
      time.sleep(0.1)
      #screen.fill((0, 0, 0))
      pygame.draw.rect(screen, (0, 0, 0), pygame.Rect(x, y, scale,scale ))
      pygame.draw.rect(screen, (0, 128, 0), pygame.Rect(x, y, scale/2,scale/2 ))
      x+=scale;
      y+=scale;
      pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(x, y, scale, scale))
      pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(50, 100, scale, scale))
      pygame.display.flip()

if __name__ == "__main__":
   #mapLoad()
   simulation()
