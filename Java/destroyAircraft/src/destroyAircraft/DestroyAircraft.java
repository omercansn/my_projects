package destroyAircraft;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JFrame;
import javax.swing.JPanel;

class GamePanel extends JPanel implements KeyListener {
	
	// set the cannon barrel's line length
	private int lineLength = 30;
	
	// set the airplane's placements
	private int airplaneX = 0;
	private int airplaneY = 40;
	
	// set the placement of cannon
	private int cannonX = (int)(950*Math.random()); // because in every launch the cannon will be placed at random places as the teacher desired
    private int cannonCenterX = cannonX +25;
    private int cannonY = 670;
    
    // set the placement of cannon barrel
    private int cannonLineX = cannonCenterX;
    private int cannonLineY = cannonY - lineLength;
    
    // set the placement of cannon bullet
    private int cannonLineMovingX1 = cannonLineX;
    private int cannonLineMovingX2 = cannonCenterX;
    private int cannonLineMovingY1 = cannonLineY;
    private int cannonLineMovingY2 = cannonY;
    
    // setting for maintaining the length of the cannon bullet when throwing (to be assigned)
    private int dist1;
	private int dist2;
	
	// set the angle with the ground
    private double angle = 90; 
    
    // set the booleans
    private boolean leftPressed = false;
    private boolean rightPressed = false;
    private boolean upPressed = false;
    private boolean success = false;
    
    
    public GamePanel(){
        setBackground(Color.cyan);
        setDoubleBuffered(true); // this one is for preventing the flickers
        addKeyListener(this);
        setFocusable(true); // Add this line to make the GamePanel focusable and then receive the key inputs
    }

    //create the game rendering
    public void paint(Graphics g) {
    	
        super.paint(g); // for rendering properly
        
        // if the mission is completed
        if(success) {
			Font f1 = new Font("Times New Roman", Font.PLAIN, 40);
			Font f2 = new Font("Times New Roman", Font.PLAIN, 30);
			g.setFont(f1);
			g.drawString("YOU WON!", 400, 300);
			g.setFont(f2);
			g.drawString("Press ESC to exit.", 400, 500);
			g.dispose();
		}
        
        // Draw cannon base
        g.setColor(Color.BLACK);
        g.fillRect(cannonCenterX - 25, cannonY, 50, 50);

        // Draw cannon line
        g.drawLine(cannonCenterX, cannonY, cannonLineX, cannonLineY);

        // another rendering stuff:
        // the airplane
        g.setColor(Color.white);
		g.fillRect(airplaneX, airplaneY, 100, 50);
        // the ground
		g.setColor(Color.black);
		g.fillRect(0, 720, 1000, 90);
        // the cannon
		g.setColor(Color.darkGray);
		g.fillRect(cannonX, cannonY, 50, 50);
        // the cannon barrel
		g.setColor(Color.black);
		g.drawLine(cannonCenterX, cannonY, cannonLineX, cannonLineY);
		
		// if up is pressed, cannon barrel appears and leaves from the cannon 
		if(upPressed) {
			g.setColor(Color.red);
			g.drawLine(cannonLineMovingX1, cannonLineMovingY1, cannonLineMovingX2, cannonLineMovingY2);
		}
		
		// if the barrel is out of the window
		if(!(cannonLineMovingX1>0 && cannonLineMovingX1<1000) || cannonLineMovingY1 < 0) {
			returnCannonLineStartPosition();
		}
		
		// if barrel meets the airplane, mission completed
		if ((cannonLineMovingX1>=airplaneX && cannonLineMovingX1<=airplaneX+100) && 
            (cannonLineMovingY1 >= airplaneY && cannonLineMovingY1 <= airplaneY+50 )) {
			returnCannonLineStartPosition();
			success = true;
		}
		
    }
    
    // key handling stuff
    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            leftPressed = true;
        } else if (key == KeyEvent.VK_RIGHT) {
            rightPressed = true;
        } else if (key == KeyEvent.VK_UP) {
        	upPressed = true;
        }
        if (key == KeyEvent.VK_ESCAPE) {
        	System.exit(0);
        }
    }

    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            leftPressed = false;
        } else if (key == KeyEvent.VK_RIGHT) {
            rightPressed = false;
        }
    }

    public void keyTyped(KeyEvent e) {}
    
    // return cannon line to start position
    public void returnCannonLineStartPosition(){
        cannonLineMovingX1 = cannonLineX;
        cannonLineMovingX2 = cannonCenterX;
        cannonLineMovingY1 = cannonLineY;
        cannonLineMovingY2 = cannonY;
        upPressed = false;
    }

    // update the values
    public void update() {
    	
        // update the airplane's values
    	airplaneX+=2;
		if(airplaneX >= 1000) airplaneX = -100;
		
		if(!upPressed) {
        	dist1 = cannonLineX-cannonCenterX;
        	dist2 = cannonLineY-cannonY;
        }
		
        if ((leftPressed && angle <= 165)) {
            angle += 1;
            updateCannonLine();
        } else if ((rightPressed && angle >= 15)) {
            angle -= 1;
            updateCannonLine();
        }
        
        if(upPressed) {
        	cannonLineMovingX1 += (dist1)*0.25;
        	cannonLineMovingX2 += (dist1)*0.25;
        	cannonLineMovingY1 += (dist2)*0.25;
        	cannonLineMovingY2 += (dist2)*0.25;
        }
    }
    
    // update cannon line's coordinates
    private void updateCannonLine() {
        double angleInRadians = Math.toRadians(angle);
        cannonLineX = cannonCenterX + (int) (lineLength * Math.cos(angleInRadians)); 
        cannonLineY = cannonY - (int) (lineLength * Math.sin(angleInRadians)); 
        if(!upPressed) {
        	cannonLineMovingX1 = cannonCenterX + (int) (lineLength * Math.cos(angleInRadians)); 
            cannonLineMovingY1 = cannonY - (int) (lineLength * Math.sin(angleInRadians)); 
        }
    }
    
    // the ultimate game loop
    public void run() {
        while (true) {
            update();
            repaint();
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    
}

public class DestroyAircraft implements WindowListener{
    
    JFrame frame = new JFrame("Destroy Aircraft");
    GamePanel panel = new GamePanel();

    // create the window
    public DestroyAircraft () {

        frame.addWindowListener(this);
        frame.add(panel);
        frame.setSize(1000, 800);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setVisible(true);
    }

    // main function
    public static void main(String[] args) {
        DestroyAircraft  game = new DestroyAircraft ();
        game.panel.run();
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

