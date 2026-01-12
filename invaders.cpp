#include <iostream>
#include <vector>
#include <conio.h>   
#include <windows.h> 
#include <cstdlib>   

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 15;

vector<vector<char>> screen(HEIGHT, vector<char>(WIDTH, ' '));

struct Player {
    int x, y;
};

struct Bullet {
    int x, y;
    bool active;
};

struct Enemy {
    int x, y;
    bool alive;
};

//drawing the screen
void drawScreen(Player& p, vector<Bullet>& bullets, vector<Enemy>& enemies) {
    system("cls");

    //clear screen
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            screen[i][j] = ' ';

    //put player
    screen[p.y][p.x] = '^';

    //put bullets
    for (auto& b : bullets)
        if (b.active && b.y >= 0)
            screen[b.y][b.x] = '|';

    //put enemies
    for (auto& e : enemies)
        if (e.alive)
            screen[e.y][e.x] = 'M';

    //print the screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << screen[i][j];
        cout << endl;
    }
}

//check if bullet hit any enemy
void checkBulletHit(vector<Bullet>& bullets, vector<Enemy>& enemies) {
    for (auto& b : bullets) {
        if (!b.active) continue;
        for (auto& e : enemies) {
            if (e.alive && b.x == e.x && b.y == e.y) {
                e.alive = false;
                b.active = false;
            }
        }
    }
}

//move enemies left/right
void moveEnemies(vector<Enemy>& enemies, int& direction) {
    bool hitEdge = false;
    for (auto& e : enemies) {
        if (!e.alive) continue;
        if ((e.x == 0 && direction == -1) || (e.x == WIDTH - 1 && direction == 1)) {
            hitEdge = true;
            break;
        }
    }

    if (hitEdge) {
        direction *= -1;
        for (auto& e : enemies)
            e.y++; //move down when hitting edge
    }
    else {
        for (auto& e : enemies)
            e.x += direction;
    }
}

int main() {
    Player player = { WIDTH / 2, HEIGHT - 1 };
    vector<Bullet> bullets;
    vector<Enemy> enemies;

    //init enemies
    for (int i = 0; i < 10; i++)
        enemies.push_back({ i * 2, 1, true });

    int enemyDirection = 1;
    bool gameOver = false;

    while (!gameOver) {
        //input
        if (_kbhit()) {
            char c = _getch();
            if (c == 'a' && player.x > 0) player.x--;
            if (c == 'd' && player.x < WIDTH - 1) player.x++;
            if (c == 'w') bullets.push_back({ player.x, player.y - 1, true });
        }

        //move bullets
        for (auto& b : bullets)
            if (b.active) b.y--;

        //check bullet hits
        checkBulletHit(bullets, enemies);

        //move enemies
        moveEnemies(enemies, enemyDirection);

        //check if enemies reach player
        for (auto& e : enemies)
            if (e.alive && e.y == player.y) gameOver = true;

        //draw screen
        drawScreen(player, bullets, enemies);

        //check win
        bool allDead = true;
        for (auto& e : enemies)
            if (e.alive) allDead = false;
        if (allDead) {
            cout << "You win!" << endl;
            break;
        }

        Sleep(100);
    }

    if (gameOver) cout << "Game Over!" << endl;
    return 0;
}
