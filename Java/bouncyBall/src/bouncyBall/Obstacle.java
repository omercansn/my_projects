package bouncyBall;

import java.awt.Graphics;
import java.util.ArrayList;

public class Obstacle {

    private int obstacleX;
    private int obstacleY;
    private int obstacleThickness;
    private int obstacleLen;
    private int obstacleSpeed;
    
    public Obstacle(int x, int y, int thickness, int len, int speed) {
        this.obstacleX = x;
        this.obstacleY = y;
        this.obstacleThickness = thickness;
        this.obstacleLen = len;
        this.obstacleSpeed = speed;
    }

    //some getters-setters
    public int getObstacleX() {
        return obstacleX;
    }

    public void setObstacleX(int obstacleX) {
        this.obstacleX = obstacleX;
    }

    public int getObstacleY() {
        return obstacleY;
    }

    public void setObstacleY(int obstacleY) {
        this.obstacleY = obstacleY;
    }

    public int getObstacleThickness() {
        return obstacleThickness;
    }

    public void setObstacleThickness(int obstacleThickness) {
        this.obstacleThickness = obstacleThickness;
    }

    public int getObstacleLen() {
        return obstacleLen;
    }

    public void setObstacleLen(int obstacleLen) {
        this.obstacleLen = obstacleLen;
    }

    public void drawObstacle(Graphics g){
        g.fillRect(obstacleX, obstacleY, obstacleLen, obstacleThickness);
    }

    public void updateObstacle(){ 
        obstacleX+=obstacleSpeed;
        if(obstacleX>=1024){
            obstacleX = 1024;
            obstacleX = -obstacleLen;
        }
    }

    public static ArrayList<Obstacle> createObstacles() {
        ArrayList<Obstacle> obstacles = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            int x = (int) (900*Math.random());
            int y = (int) (550-150*i);
            int thickness = 20;
            int len = 100+(int)(200*Math.random());
            int speed = 1+(int)(4*Math.random());
            Obstacle obstacle = new Obstacle(x, y, thickness, len, speed);
            obstacles.add(obstacle);
        }
        return obstacles;
    }
}
