package pingPong;


import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.FloatControl;

import java.io.File;

class GamePanel extends Canvas implements KeyListener {
	
	public final int screenWidth = 1000;
	public final int screenHeight = 700;

	private double angle = generateAngle(); // consider that the angular direction is CLOCKWISE from 0 to 360!

    private final int ballXInitial = 495;
    private final int ballYInitial = 345;
    private final int ballSpeedInitial = 6 ;

    private int ballX = ballXInitial;
	private int ballY = ballYInitial;
    private double ballSpeed = ballSpeedInitial;

    private int rect1X = 100, rect1Y = 300;
    private int rect2X = 880, rect2Y = 300;

    private boolean WPressed = false, SPressed = false, upPressed = false, downPressed = false, spacePressed = false;
    private boolean start = false, esc = false, collision = false;

    private int score1P = 0;
    private int score2P = 0;
    
    public Clip backgroundMusic;
    public Clip hit;
    public Clip tada;
    public Clip done;

    public GamePanel(){
        setBackground(new Color(200, 125, 89));
        addKeyListener(this);
        loadAudioFiles(); 
    }

    public void loadAudioFiles(){
        try {
            System.out.println("Loading audio files...");

            File audioFile1 = new File("res/audio/music.wav");
            AudioInputStream audioInputStream1 = AudioSystem.getAudioInputStream(audioFile1);
            backgroundMusic = AudioSystem.getClip();
            backgroundMusic.open(audioInputStream1);
            backgroundMusic.loop(Clip.LOOP_CONTINUOUSLY);       
            
            FloatControl volumeControl = (FloatControl) backgroundMusic.getControl(FloatControl.Type.MASTER_GAIN);
            float volumeLevel = -12.0f; 
            volumeControl.setValue(volumeLevel);

            File audioFile2 = new File("res/audio/hit.wav");
            AudioInputStream audioInputStream2 = AudioSystem.getAudioInputStream(audioFile2);
            hit = AudioSystem.getClip();
            hit.open(audioInputStream2);

            File audioFile3 = new File("res/audio/tada.wav");
            AudioInputStream audioInputStream3 = AudioSystem.getAudioInputStream(audioFile3);
            tada = AudioSystem.getClip();
            tada.open(audioInputStream3);

            File audioFile4 = new File("res/audio/done.wav");
            AudioInputStream audioInputStream4 = AudioSystem.getAudioInputStream(audioFile4);
            done = AudioSystem.getClip();
            done.open(audioInputStream4);

            System.out.println("Audio files loaded successfully.");

        } catch (Exception e) {
            System.out.println("Error loading audio file:");
            e.printStackTrace();
        }
    }

    public double generateAngle(){
        double angle = 0;
        do{
            angle = (360*Math.random());
        } while((angle>60 && angle<120) || (angle>240 && angle<320) || (angle>=0 && angle<30) || (angle>150 && angle<210) || angle>330);
        
        return angle;
    }
    public void paint(Graphics g) {
        Font f = new Font("Times New Roman", Font.BOLD, 30);
        g.setFont(f);
        if(score1P == 5 || score2P == 5){
            if(score1P == 5){
                g.drawString("Player 1 won the game !", 350, 350);
            }
            else if(score2P == 5){
                g.drawString("Player 2 won the game !", 350, 350);
            }
            backgroundMusic.stop();
            
            done.start();
            g.drawString("Press SPACE to play again.", 315, 400);
            g.drawString("Press ESC to exit.", 380, 450);
            g.dispose();
            if(spacePressed){
                start = false;
                score1P = 0;
                score2P = 0;

                done.setFramePosition(0);
                done.stop();
                
                backgroundMusic.setFramePosition(0);
                backgroundMusic.start();
            }
            if(esc){
              System.exit(0);
            }
        }

    	g.setColor(new Color(210,240,200));
    	g.fillRect(0,0, 50, screenHeight);
        g.fillRect(950,0, 50, screenHeight);

        g.setColor(Color.darkGray);
        g.fillRect(rect1X, rect1Y, 20, 100);
        g.fillRect(rect2X, rect2Y, 20, 100);

    	g.setColor(Color.black);
    	g.fillOval(ballX, ballY, 10, 10);

        g.drawString(score1P + " - " + score2P, 470, 30);

        if(start){
            double speed = 10;
            if(WPressed && rect1Y >= 10){
                rect1Y -= speed;
            }
            if(SPressed && rect1Y <= 570){
                rect1Y += speed;
            }
            if(upPressed && rect2Y >= 10){
                rect2Y -= speed;
            }
            if(downPressed && rect2Y <= 570){
                rect2Y += speed;
            }

            double angleInRadians = Math.toRadians(angle);
            if(collision){
                hit.setFramePosition(0);
                hit.start();
                
                collision = false;
                
            }
            double ballSpeedX = (ballSpeed * Math.cos(angleInRadians)); 
            double ballSpeedY = (ballSpeed * Math.sin(angleInRadians));

            ballY += ballSpeedY;
            ballX += ballSpeedX;
            
            // Check for boundary conditions and update the angle if needed

            if(ballSpeedY > 0 && (((ballY >= rect1Y-10 && ballY <= rect1Y-5) || (ballY >= rect1Y+95 && ballY <= rect1Y+100)) && (ballX>=rect1X - 5 && ballX <= rect1X + 5)) ){
                angle = -angle;
            }
            else if(ballSpeedY < 0 && ((ballY >= rect2Y-10 && ballY <= rect2Y-5) || (ballY >= rect2Y+95 && ballY <= rect2Y+100)) && (ballX>=rect2X - 5 && ballX <= rect2X + 5)) 
            {
                angle = -angle;
            }
            else 
             
            {
                if (ballSpeedX < 0 && (ballX >= rect1X && ballX <= rect1X + 20) && 
                (ballY >= rect1Y - 10 && ballY <= rect1Y + 95)){
                collision = true;
                angle = 180 - angle;
            }
            if (ballSpeedX > 0 && (ballX >= rect2X - 10 && ballX <= rect2X + 10) && 
                (ballY >= rect2Y - 10 && ballY <= rect2Y + 95)){
                collision = true;
                angle = 180 - angle;
            }
            }
            

            
            if (ballY < 0 || ballY > screenHeight - 40) {
                angle = -angle;
            }

            if(ballX < 0){
                tada.setFramePosition(0);
                tada.start();
                score2P++;
                start = false;
            }
            if(ballX > 1000){
                tada.setFramePosition(0);
                tada.start();
                score1P++;
                start = false;
            }

        } else {
            angle = generateAngle();
            rect1X = 100;
            rect1Y = 300;
            rect2X = 880; 
            rect2Y = 300;
            ballX = ballXInitial;
            ballY = ballYInitial;
            ballSpeed = ballSpeedInitial;
            if(score1P == 0 && score2P == 0){
                g.drawString("THE PINGPONG GAME", 340, 215);
            }
            g.drawString("Press SPACE to start the game", 300, 485);
            
            
        }
        
    	try{
            Thread.sleep(15);
        } catch(Exception e) {
            e.printStackTrace();
        }
        repaint();
    }

    // some KeyListener stuff
    public void keyTyped(KeyEvent e) {
    }


    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        if(key == KeyEvent.VK_W){
            WPressed = true;
        }
        if(key == KeyEvent.VK_S){
            SPressed = true;
        }
        if(key == KeyEvent.VK_UP){
            upPressed = true;
        }
        if(key == KeyEvent.VK_DOWN){
            downPressed = true; 
        }
        if(key == KeyEvent.VK_SPACE){
            spacePressed = true;
            start = true;
        }
        if(key == KeyEvent.VK_ESCAPE){
            esc = true;
        }
    }


    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();
        if(key == KeyEvent.VK_W){
            WPressed = false;
        }
        if(key == KeyEvent.VK_S){
            SPressed = false; 
        }
        if(key == KeyEvent.VK_UP){
            upPressed = false; 
        }
        if(key == KeyEvent.VK_DOWN){
            downPressed = false; 
        }
        if(key == KeyEvent.VK_SPACE){
            spacePressed = false;
        }
    }

}


public class pingPong implements WindowListener {
    Frame frame = new Frame("Ping Pong v0.2");
    GamePanel panel = new GamePanel();

    // create the window
    public pingPong () {

        frame.addWindowListener(this);
        frame.add(panel);
        frame.setSize(panel.screenWidth, panel.screenHeight);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setVisible(true);
        panel.backgroundMusic.start();
    }

    // main function
    public static void main(String[] args) {
    	pingPong  game = new pingPong ();
    }

    // some WindowListener stuff
    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}