package bouncyBall;

import java.awt.Graphics;
import java.util.ArrayList;

public class Player{

    private GamePanel gp;
    private KeyHandler kh;
    private ArrayList<Obstacle> obstacles;
    
    private final int ballSize = 20;
    private final int ballXInitial = 50 + (int) (800 * Math.random());
    private final int ballYInitial;
    private int ballX;
    private int ballY;
    private int t = 0;
    private int ballSpeedY;

    //some getters-setters
    public void setX(int x){
        this.ballX = x;
    }
    public void setY(int y){
        this.ballX = y;
    }
    public int getX(){
        return this.ballX;
    }
    public int getBallXInitial() {
        return this.ballXInitial;
    }
    public int getBallYInitial() {
        return this.ballYInitial;
    }
    public int getY(){
        return this.ballY;
    }
    public int getBallSize(){
        return this.ballSize;
    }

    public int getBallSpeedY(){
        return this.ballSpeedY;
    }

    public void setBallSpeedY(int speed){
        this.ballSpeedY = speed;
    }

    public Player(GamePanel gp, ArrayList<Obstacle> obstacles, KeyHandler kh) {
        this.gp = gp;
        this.kh = kh;
        ballYInitial= gp.groundStartY - ballSize;
        this.obstacles = obstacles;
        this.ballX = ballXInitial;
        this.ballY = ballYInitial;
    }

    public void update() {   
        if (kh.leftPressed && ballX > 0) {
            ballX -= 5;
        }
        if (kh.rightPressed && ballX + ballSize <= gp.getWidth()) {
            ballX += 5;
        }
        t += 2;

        // Check for collision with ground
        if (ballY + ballSize >= gp.groundStartY) {
            ballY = gp.groundStartY - ballSize;
            t = 0;
        }

        // Check for collision with obstacles
        for (Obstacle obstacle : obstacles) {
            obstacle.updateObstacle();
            int x = obstacle.getObstacleX();
            int len = obstacle.getObstacleLen();
            int y = obstacle.getObstacleY();
            int thicc = obstacle.getObstacleThickness();
            
            if(ballSpeedY > 0){
                if (ballX < x + len &&
                    ballX + ballSize > x &&
                    ballY < y + thicc &&
                    ballY + ballSize > y)
                    {
                    t = 0;
                }
                if(ballX + ballSize > gp.endPlatformX && 
                    ballX < gp.endPlatformX + gp.endPlatformLength && 
                    ballY > gp.endPlatformY-ballSize && 
                    ballY < 100+ballSize+gp.endPlatformThickness){
                    t = 0;
                }

            }
            
        }
        ballSpeedY = (t * t - 4500) / 500;
        ballY += ballSpeedY;
    }

    public void draw(Graphics g) {
        g.fillOval(ballX, ballY, ballSize, ballSize);
    }

    
    
}
