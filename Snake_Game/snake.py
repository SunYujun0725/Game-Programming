import random,sys,time,pygame
from pygame.locals import *
from collections import deque

SCREEN_WIDTH = 600   #螢幕寬度
SCREEN_HEIGHT = 520  #螢幕高度
SIZE = 20            #格子size

def print_text(screen, font, x, y, text, fcolor=(255, 255, 255)):
    imgText = font.render(text, True, fcolor)
    screen.blit(imgText, (x, y))


def main():
    pygame.init()  #初始化pygame
    pygame.mixer.init() #初始化音效
    screen = pygame.display.set_mode((SCREEN_WIDTH,SCREEN_HEIGHT))  #設定視窗
    pygame.display.set_caption("狒狒's snake")

    #設定視窗內物件顏色、字體
    foodcolor = (255,0,0)     #食物的顏色(紅)
    blue = (28,134,238)       #蛇的顏色 
    red = (200,30,30)         #Game over的顏色
    bg_color = (150,150,150)     #背景的顏色
    black = (110,110,110)           #網格線的顏色
    line_width = 1            #網格線的寬度

    score_font = pygame.font.SysFont("arial", 20, bold=False, italic=False) #得分的字體 SimHei
    game_over_font = pygame.font.Font(None,76)    #Game Over的字體
    fwidth, fheight = game_over_font.size('GAME OVER')

    #起始方向，向右
    pos_x = 1
    pos_y = 0
    #如果蛇正在向右移動，突然快速向下向左，反應刷新不夠快，向下會被向左蓋掉，導致蛇向後退，直接game over
    # f 就是用來防止這情況發生
    f = True

    #範圍
    scope_x = (0, SCREEN_WIDTH // SIZE - 1)
    scope_y = (2, SCREEN_HEIGHT // SIZE - 1)
    #蛇
    snake = deque()
    #食物
    food_x = 0
    food_y = 0

    #初始化蛇
    def init_snake():
        nonlocal snake
        snake.clear()
        snake.append((2, scope_y[0]))
        snake.append((1, scope_y[0]))
        snake.append((0, scope_y[0]))
    
    #食物
    def create_food():
        nonlocal food_x, food_y
        food_x = random.randint(scope_x[0], scope_x[1])
        food_y = random.randint(scope_y[0], scope_y[1])
        #當食物隨機到蛇身上就要重新產生
        while (food_x, food_y) in snake:
            food_x = random.randint(scope_x[0], scope_x[1])
            food_y = random.randint(scope_y[0], scope_y[1])
    
    init_snake()
    create_food()

    game_over = True
    game_start = False
    score = 0
    original_speed = 0.2  #0.5
    speed = original_speed
    last_move_time = None
    stop = False
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:          #按下esc鍵離開遊戲
                sys.exit()
            elif event.type == pygame.KEYDOWN:     #按下鍵盤
                if event.key == pygame.K_RETURN:  #按下enter鍵(開始遊戲)
                    if game_over:
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
                        game_start = True
                        game_over = False
                        f = True
                        init_snake()
                        create_food()
                        pos_x = 1
                        pos_y = 0
                        score = 0
                        speed = 0.2 #
                        last_move_time = time.time()
                elif event.key == pygame.K_SPACE: #按下空白鍵(暫停跟開始)
                    if not game_over:
                        stop = not stop
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
                elif event.key in (pygame.K_a, pygame.K_LEFT):  #向左
                     #判斷防止向左移動時按向右鍵，導致蛇死掉
                    if f and not pos_x:
                        pos_x = -1
                        pos_y = 0
                        f = False
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
                elif event.key in (pygame.K_d, pygame.K_RIGHT): #向右
                    if f and not pos_x:
                        pos_x = 1
                        pos_y = 0
                        f = False
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
                elif event.key in (pygame.K_w, pygame.K_UP):    #向上
                    if f and not pos_y:
                        pos_x = 0
                        pos_y = -1
                        f = False
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
                elif event.key in (pygame.K_s, pygame.K_DOWN):  #向下
                    if f and not pos_y:
                        pos_x = 0
                        pos_y = 1
                        f = False
                        pygame.mixer.music.load("turn.ogg")  #播音效
                        pygame.mixer.music.set_volume(0.2)
                        pygame.mixer.music.play()
    

        #填充背景
        screen.fill(bg_color)
        #畫格子線
        #線 pygame.draw.line(畫布, 顏色, (x坐標1, y坐標1), (x坐標2, y坐標2), 線寬)
        for x in range(SIZE, SCREEN_WIDTH, SIZE):   #直線
            pygame.draw.line(screen, black, (x, scope_y[0] * SIZE), (x, SCREEN_HEIGHT), line_width)
        for y in range(scope_y[0] * SIZE, SCREEN_HEIGHT, SIZE):  #橫線
            pygame.draw.line(screen, black, (0, y), (SCREEN_WIDTH, y), line_width)

        if game_over:
            if game_start:
                print_text(screen, game_over_font, (SCREEN_WIDTH - fwidth)//2, (SCREEN_HEIGHT - fheight)//2, "GAME OVER", red)
        else:
            current_time = time.time()
            if current_time - last_move_time > speed:
                if not stop:
                    f = True
                    last_move_time = current_time
                    next_step = (snake[0][0] + pos_x, snake[0][1] + pos_y)
                    if next_step[0] == food_x and next_step[1] == food_y:  #吃到食物
                        pygame.mixer.music.load("eat.ogg")  #播音效
                        pygame.mixer.music.set_volume(2)
                        pygame.mixer.music.play()
                        create_food()
                        snake.appendleft(next_step)
                        score += 10
                        #speed = original_speed - 0.03 * (score // 100)  #每100分加快速度
                    else:
                        if scope_x[0] <= next_step[0] <= scope_x[1] and scope_y[0] <= next_step[1] <= scope_y[1] and next_step not in snake:
                            snake.appendleft(next_step)
                            snake.pop()
                        else:
                            pygame.mixer.music.load("game_over.ogg")  #播音效
                            pygame.mixer.music.set_volume(2)
                            pygame.mixer.music.play()
                            game_over = True
        #畫食物
        if not game_over:
            #矩形 pygame.draw.rect(畫布, 顏色, [x坐標, y坐標, 寬度, 高度], 線寬)
            pygame.draw.rect(screen, foodcolor, (food_x * SIZE, food_y * SIZE, SIZE, SIZE), 0)
        #畫蛇
        for s in snake:
            pygame.draw.rect(screen, blue, (s[0] * SIZE + line_width, s[1] * SIZE + line_width,
                                            SIZE - line_width * 2, SIZE - line_width * 2), 0)

        #print_text(screen, score_font, 50, 10, f'speed: {score//100}')  #速度
        print_text(screen, score_font, 10, 10, f'score: {score}')      #得分

        pygame.display.update()

#程式有引用其他模組，避免不該執行的地方被又執行一次
if __name__ == '__main__':
    main()