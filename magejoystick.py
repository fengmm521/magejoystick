#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pygame
from pygame.locals import *
from sys import exit

BG_IMAGE = 'ball.png'
'''
  事件             产生途径              参数
  QUIT         用户按下关闭按钮          none
  ATIVEEVENT         Pygame被激活或者隐藏          gain, state
  KEYDOWN         键盘被按下              unicode, key, mod
  KEYUP         键盘被放开              key, mod
  MOUSEMOTION         鼠标移动              pos, rel, buttons
  MOUSEBUTTONDOWN     鼠标按下              pos, button
  MOUSEBUTTONUP     鼠标放开              pos, button
  JOYAXISMOTION     游戏手柄(Joystick or pad)移动      joy, axis, value
  JOYBALLMOTION     游戏球(Joy ball)?移动      joy, axis, value
  JOYHATMOTION     游戏手柄(Joystick)?移动      joy, axis, value
  JOYBUTTONDOWN     游戏手柄按下              joy, button
  JOYBUTTONUP         游戏手柄放开              joy, button
  VIDEORESIZE         Pygame窗口缩放          size, w, h
  VIDEOEXPOSE         Pygame窗口部分公开(expose)      none
  USEREVENT         触发了一个用户事件          code
'''
def main():
    pygame.init()
    count = pygame.joystick.get_count()
    print count
    j  = pygame.joystick.Joystick(0)
    j.init()
    screen = pygame.display.set_mode((500, 500), 0, 32)
    bg = pygame.image.load(BG_IMAGE).convert()
    x, y = 0, 0
    move_x, move_y = 0, 0

    movestep = 3

    while 1:
        for event in pygame.event.get():
            print(event.type)
            if event.type == QUIT:
                exit()
            if event.type == JOYAXISMOTION:#游戏手柄(Joystick or pad)移动,joy, axis, value
                print('JOYAXISMOTION')
                print(event.joy,event.axis,event.value)
                if event.axis == 0:#左右
                    if event.value > 0.01 or event.value < 0.01:
                        move_x = movestep * event.value
                    elif event.value > 0.99:
                        move_x = movestep
                    elif event.value < -0.99:
                        move_x = -movestep
                    else:
                        move_y = 0
                        move_x = 0
                elif event.axis == 1:#上下
                    if event.value > 0.01 or event.value < 0.01:
                        move_y = movestep * event.value
                    elif event.value > 0.99:
                        move_y = movestep
                    elif event.value < -0.99:
                        move_y = -movestep
                    else:
                        move_y = 0
                        move_x = 0
                elif event.axis == 3:#左右
                    if event.value > 0.01 or event.value < 0.01:
                        move_x = movestep * event.value
                    elif event.value > 0.99:
                        move_x = movestep
                    elif event.value < -0.99:
                        move_x = -movestep
                    else:
                        move_y = 0
                        move_x = 0
                elif event.axis == 4:#上下
                    if event.value > 0.01 or event.value < 0.01:
                        move_y = movestep * event.value
                    elif event.value > 0.99:
                        move_y = movestep
                    elif event.value < -0.99:
                        move_y = -movestep
                    else:
                        move_y = 0
                        move_x = 0
                else:
                    move_y = 0
                    move_x = 0
                # if event.axis == 


            elif event.type == JOYBALLMOTION:#游戏球(Joy ball)?移动,joy, axis, value
                print('JOYBALLMOTION')
                print(event.joy,event.axis,event.value)

            elif event.type == JOYHATMOTION: #游戏手柄(Joystick)?移动,joy, axis, value
                print('JOYBALLMOTION')
                print(event.joy,event.axis,event.value)

            elif event.type == JOYBUTTONDOWN:   #游戏手柄按下,joy, button
                print('JOYBUTTONDOWN')
                print(event.joy,event.button)

            elif event.type == JOYBUTTONUP:     #游戏手柄弹起,joy, button
                print('JOYBUTTONUP')
                print(event.joy,event.button)


            elif event.type == KEYDOWN:         #按键按下
                print('KEYDOWN')
                print(event.key)
                #event.key返回的是一个数字值，而K_LEFT,K_UP,K_RIGHT,K_DOWN等都是常量，
                #他们代表的也是一个数字值，这些数字值可以用：print(event.key)获取到
                #如：K_LEFT = 276
                #  K_UP = 273
                #所以下面的代码可以替换为：
                #if event.key == 276:
                #  move_x = -10
                if event.key == K_LEFT:         #方向左按下
                    move_x = -10
                elif event.key == K_UP:         #方向上按下
                    move_y = -10
                elif event.key == K_RIGHT:      #方向右按下
                    move_x = 10
                elif event.key == K_DOWN:       #方向下按下
                    move_y = 10
            elif event.type == KEYUP:           #按键弹起
                print('KEYUP')
                move_x = 0
                move_y = 0
            elif event.type == MOUSEMOTION:     #鼠标移动
                print('MOUSEMOTION')
                print(event.pos)
            x += move_x
            y += move_y
            #print(x, y)
            screen.fill((0, 0, 0))
            screen.blit(bg, (x, y))
            pygame.display.update()

if __name__ == '__main__':
    main()
#在数据库中查找某行数据
#select * from test id not in('2','3');#id不含2,3或者去掉not表示含有
#查数据
# select * from test;  #取所有数据
# select * from test limit 0,2;  #取前两条数据 
# select * from test email like '%qq%' #查含有qq字符 _表示一个 %表示多个
# select * from test order by id asc;#降序desc
# select * from test id not in('2','3');#id不含2,3或者去掉not表示含有
# select * from test timer between 1 and 10;#数据在1,10之间
#  
# #---------------------------表连接知识------------------------------
# #等值连接又叫内链接 inner join 只返回两个表中连接字段相等的行
# select * from A inner join B on A.id = B.id; #写法1
# select * from A,B where A.id = B.id; #写法2
# select a.id,a.title from A a inner join B b on a.id=b.id and a.id=1;#写法3 表的临时名称
# select a.id as ID,a.title as 标题 from A inner join B on A.id=B.id;#添加as字句
#  
# #左连接又叫外连接 left join 返回左表中所有记录和右表中连接字段相等的记录
# select * from A left join B on A.id = B.id;
# select * from A left join (B,C,D) on (B.i1=A.i1 and C.i2=A.i2 and D.i3 = A.i3);#复杂连接
# #右连接又叫外连接 right join 返回右表中所有记录和左表中连接字段相等的记录
# select * from A right join B on A.id = B.id;
# #完整外部链接 full join 返回左右表中所有数据
# select * from A full join B on A.id = B.id;
# #交叉连接 没有where字句 返回卡迪尔积
# select * from A cross join B;
