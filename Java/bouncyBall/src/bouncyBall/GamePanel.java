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
    private ArrayList<Coin> coins;
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
    private boolean endGateDrawn = false;
    private boolean endGateActivated = false;
    
    private final int FPS = 60; // Frames per second
    private final int countdown = 60; // countdown
    private double elapsedTimeSeconds;
    private final long targetTime = 1000 / FPS; // Target time per frame

    public Clip main;
    public Clip done;
    public Clip coinSound;
    public Clip endgate;
    public Clip tenSec;
    public Clip gameOver;

    public GamePanel(){
        obstacles = Obstacle.createObstacles(); // Call the static method to create obstacles
        coins = Coin.createCoins();
        ball = new Player(this, obstacles, kh);
        setBackground(Color.cyan);
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

            File file3 = new File("res/audio/coin.wav");
            AudioInputStream as3 = AudioSystem.getAudioInputStream(file3);
            coinSound = AudioSystem.getClip();
            coinSound.open(as3);

            File file4 = new File("res/audio/endgate.wav");
            AudioInputStream as4 = AudioSystem.getAudioInputStream(file4);
            endgate = AudioSystem.getClip();
            endgate.open(as4);

            File file5 = new File("res/audio/10sec.wav");
            AudioInputStream as5 = AudioSystem.getAudioInputStream(file5);
            tenSec = AudioSystem.getClip();
            tenSec.open(as5);

            File file6 = new File("res/audio/game_over.wav");
            AudioInputStream as6 = AudioSystem.getAudioInputStream(file6);
            gameOver = AudioSystem.getClip();
            gameOver.open(as6);

            System.out.println("Audio files loaded succesfully.");
        } catch (Exception e) {
            System.out.println("Error loading audio file:");
            e.printStackTrace();
        }
    }

    public void paint(Graphics g){

        if(countdown-elapsedTimeSeconds <= 0){
            tenSec.stop();
            gameOver.start();
            Font f = new Font("Times New Roman", Font.BOLD, 40);
            g.setFont(f);
            setBackground(Color.RED);
            g.drawString("GAME OVER !", 400, 300);
            g.drawString("Press ESC to exit.", 380, 400);
            g.dispose();
            kh.gameFinished = true;
        }
        else if(countdown-elapsedTimeSeconds > 0 && countdown-elapsedTimeSeconds <= 10){
            if(countdown-elapsedTimeSeconds > 5){
                setBackground(new Color(224,224,0));
            }
            else{
                setBackground(new Color(255,128,0));
            }
            
            main.stop();
            tenSec.start();
        }

        if(endGateDrawn && 
        ball.getX() >= endGateX && 
        ball.getX() <= endGateX + endGateWidth && 
        ball.getY() >= endGateY - ball.getBallSize() && 
        ball.getY() <= endGateY - ball.getBallSize() + endGateHeight){
            running = false;
            main.stop();
            tenSec.stop();
            done.start();
            setBackground(new Color(0,255,128));
            Font f = new Font("Times New Roman", Font.BOLD, 40);
            g.setFont(f);
            g.drawString("YOU WON !", 420, 300);
            g.drawString("Press ESC to exit.", 380, 400);
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
            g.setColor(Color.gray);
            for (Coin coin : coins){
                coin.drawCoins(g);
                coin.removeCoin(ball, coins);
                if(coin.coinCollected){
                    coinSound.setFramePosition(0);
                    coinSound.start();
                    coin.coinCollected = false;
                }
                
                if(coin.allCoinsCollected){
                    endGateActivated = true;
                    endgate.start();
                }
            }
        }
        
        g.setColor(new Color(0, 64, 0));
        ball.draw(g);
        if(endGateActivated){
            g.setColor(Color.red);
            g.fillRect(endGateX, endGateY, endGateWidth, endGateHeight);
            endGateDrawn = true;
        } 
        Font F = new Font("Times New Roman", Font.ITALIC, 20);
        g.setFont(F);
        g.setColor(Color.black);
        g.drawString("Seconds Left: " + (countdown-(int)elapsedTimeSeconds), 850, 30);
        g.drawString("Coins Left: " + coins.size(), 20, 30);
        
    }
        

    public void update(){
        for (Obstacle obstacle : obstacles) {
            obstacle.updateObstacle();
        }
        ball.updateBall();
    }
    public void run() {
        long current, wait;
        long start = System.nanoTime(); // Store the start time
        while (running) {
            current = System.nanoTime();
            update();
            repaint();
            elapsedTimeSeconds = (current - start) / 1000000000.0;
            wait = targetTime - (System.nanoTime() - current)/ 1000000; 
            if (wait > 0) {
                try {
                    Thread.sleep(wait);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
        
        
    }
}
