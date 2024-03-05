package deneme2;


import java.awt.*;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.awt.event.*;

class ScreenManager{
	private GraphicsDevice vc;
	public ScreenManager() {
		GraphicsEnvironment e = GraphicsEnvironment.getLocalGraphicsEnvironment();
		vc = e.getDefaultScreenDevice();
	}
	
	public DisplayMode[] getCompatibleDisplayModes() {
		return vc.getDisplayModes();
	}
}

class kanvas02 extends Canvas implements KeyListener
{
	Font f1 = new Font("Times New Roman", Font.PLAIN,50);
	Font f2 = new Font("Times New Roman", Font.PLAIN,25);
	private int t = 0;
	private int x = 0, randomX = (int)(700*Math.random()+200);
	private int y = 40; 
	private int circleX = x+30, circleY = y+60;
	private int FPS = 100;
	boolean isPressed = false, success = false;
	public kanvas02()
	{
		setBackground(Color.yellow);
		addKeyListener(this);   
	}
	
	public void paint(Graphics p)
	{  
		
		if(x>=1000) {
			x=-100;
			circleX = x+30; 
		}
		else if(circleY>650) {
			t=0;
			circleX = x+30; 
			circleY = y+60;
			isPressed = false;
		}
		else if((randomX-30<=circleX && circleX<=randomX+100) && (circleY>580)) {
			t=0;
			circleX = x+30;
			circleY = y+60;
			isPressed = false;
			success = true;
		}
		else if(success) {
//			p.setFont(f1);
//			p.drawString("YOU WON!", 400, 300);
			p.dispose();
		}
		else {
			p.setColor(Color.black);
//			p.setFont(f2);
//			p.drawString("LEVEL 1", 400, 25);
			p.fillRect(x, y, 100, 60);  
			p.setColor(Color.black);
			p.fillRect(0,650, 1000, 60);
			x+=3; circleX +=3;
			p.setColor(Color.green);
			p.fillOval(circleX, circleY, 30, 30);
			p.setColor(Color.red);
			p.fillRect(randomX,590, 100, 60);
		}
		if(isPressed) {
			t+=2;
			circleX+=3;
			circleY+=t*t/200;
		}
		try {
			Thread.sleep(10);
		}
		catch(Exception e) {}
		repaint();
	}
	
	public void keyPressed(KeyEvent e)
	{
		int tus = e.getKeyCode();
		if(tus == KeyEvent.VK_SPACE) {
			isPressed = true;
		}
		if(tus == KeyEvent.VK_ESCAPE) {
			success = false;
		}
	}	
	public void keyReleased(KeyEvent e) {
	}	
	public void keyTyped(KeyEvent e) {}			   
}

public class klavye01 implements WindowListener
{
	private Frame a;
	private kanvas02 k;

	public klavye01()
	{
		a = new Frame();
		k = new kanvas02();
		a.addWindowListener(this);
		a.add(k);
		a.setSize(1000,700);
		a.setResizable(false);
		a.setVisible(true);
	}
	
	public static void main(String args[])
	{
		klavye01 uygulama = new klavye01();
	}

	public void windowOpened(WindowEvent e) {}
	public void windowClosing(WindowEvent e) 
	{
		System.exit(0);
	}
	public void windowClosed(WindowEvent e) {}
	public void windowIconified(WindowEvent e) {}
	public void windowDeiconified(WindowEvent e) {}
	public void windowActivated(WindowEvent e) {}
	public void windowDeactivated(WindowEvent e) {}
}

