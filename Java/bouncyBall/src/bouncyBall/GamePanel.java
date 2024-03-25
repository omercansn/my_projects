package bouncyBall;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.io.File;
import java.util.ArrayList;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class GamePanel extends Canvas implements Runnable{

    private Player ball;
    private ArrayList<Obstacle> obstacles;
    private KeyHandler kh = new KeyHandler();
  
    public final int groundStartX = 0;
    public final int groundStartY = 680;
    public final int groundWidth = 1024;
    public final int groundHeight = 80;

    public final int endPlatformX = (int)(875*Math.random());
    public final int endPlatformY = 100;
    public final int endPlatformLength = 150;
    public final int endPlatformThickness = 20;

    public final int endGateX = endPlatformX + 50;
    public final int endGateY = 50;
    public final int endGateWidth = 50;
    public final int endGateHeight = 50;

    
    private boolean running = true;
    
    private final int FPS = 60; // Frames per second
    private final long targetTime = 1000 / FPS; // Target time per frame

    public Clip main;
    public Clip done;

    public GamePanel(){
        obstacles = Obstacle.createObstacles(); // Call the static method to create obstacles
        ball = new Player(this, obstacles, kh);
        setBackground(Color.white);
        addKeyListener(kh);
        setFocusable(true);
        loadAudioFiles();
    }

    public void loadAudioFiles(){
        System.out.println("Loading audio files...");
        try{
            File file1 = new File("res/audio/main.wav");
            AudioInputStream as1 = AudioSystem.getAudioInputStream(file1);
            main = AudioSystem.getClip();
            main.open(as1);
            main.loop(Clip.LOOP_CONTINUOUSLY);

            File file2 = new File("res/audio/done.wav");
            AudioInputStream as2 = AudioSystem.getAudioInputStream(file2);
            done = AudioSystem.getClip();
            done.open(as2);

            System.out.println("Audio files loaded succesfully.");
        } catch (Exception e) {
            System.out.println("Error loading audio file:");
            e.printStackTrace();
        }
    }

    public void paint(Graphics g){
        if(ball.getX() >= endGateX && 
        ball.getX() <= endGateX + endGateWidth && 
        ball.getY() >= endGateY - ball.getBallSize() && 
        ball.getY() <= endGateY - ball.getBallSize() + endGateHeight){
            running = false;
            main.stop();
            done.start();
            Font f = new Font("Times New Roman", Font.BOLD, 40);
            g.setFont(f);
            g.drawString("YOU WON!", 440, 300);
            g.drawString("Press ESC to exit.", 400, 400);
            g.dispose();
            kh.gameFinished = true;
        }
        else {
            g.setColor(Color.black);
            g.fillRect(groundStartX, groundStartY, groundWidth, groundHeight);
            g.fillRect(endPlatformX, endPlatformY, endPlatformLength, endPlatformThickness);
            for (Obstacle obstacle : obstacles) {
                obstacle.drawObstacle(g);  
            }
            g.setColor(new Color(128, 128, 0));
            ball.draw(g);
            g.setColor(Color.red);
            g.fillRect(endGateX, endGateY, endGateWidth, endGateHeight);
        }
        
    }

    public void update(){
        for (Obstacle obstacle : obstacles) {
            obstacle.updateObstacle();
        }
        ball.update();
    }
    public void run() {
        long start, elapsed, wait;

        while (running) {
            start = System.nanoTime();
            update();
            repaint();
            elapsed = System.nanoTime() - start;
            wait = targetTime - elapsed / 1000000; // Convert nanoseconds to milliseconds

            if (wait > 0) {
                try {
                    Thread.sleep(wait);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
