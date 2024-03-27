package bouncyBall;

import java.awt.Frame;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class Main implements WindowListener  {

    Frame frame;
    GamePanel panel;
    KeyHandler kh;

    public final int screenWidth = 1024;
    public final int screenHeight = 768;

    public Main(){ 

        frame = new Frame("Bouncy Ball v0.85");
        panel = new GamePanel();

        frame.addWindowListener(this);
        frame.add(panel);
        frame.setSize(screenWidth, screenHeight);
        frame.setLocationRelativeTo(null); 
        frame.setResizable(false);
        frame.setVisible(true);

    }
    
    public static void main(String[] args) throws Exception {
        Main game = new Main();
        game.panel.run();
    }

    public void windowOpened(WindowEvent e) {
    }
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void windowClosed(WindowEvent e) {
        
    }
    public void windowIconified(WindowEvent e) {
    }
    public void windowDeiconified(WindowEvent e) {
    }
    public void windowActivated(WindowEvent e) {
    }
    public void windowDeactivated(WindowEvent e) {
    }
}
