package deneme2;

import java.awt.*;
import java.awt.event.*;

class kanvas extends Canvas{
		private int x1 = 0;
		private int FPS = 45;
		boolean direction = true; // left to right; if false, right to left
		public kanvas() {
			setBackground(Color.orange);
		}
		
		public void paint(Graphics p) {
			/* first etude
			p.drawString("mer", x1, y1);
			p.drawString("haba", x2, y2);
			if(x1==x2&&y2==y1) {
				p.clearRect(0, 0, getWidth(), getHeight());
				p.drawString("merhaba", x1, y2);
				return;
			} else {
				x1+=9;
				y2-=5;
			}
			try {
				Thread.sleep(1000/FPS);
				
			}
			catch(Exception err) {
				
			}
			repaint();
			*/
			
			/*second etude*/ 
			p.drawString("merhaba", x1, 200);
			if(direction) {
				x1+=5;
				if(x1>=940) {
					direction = false;
				}
			}
			else if(!direction) {
				x1-=5;
				if(x1<=0) {
					direction = true;
				}
			}
			
			try {
				Thread.sleep(1000/FPS);
				
			}
			catch(Exception err) {
				
			}
			repaint();
			
			
			/* third etude
			int oval1 = (int)(50*Math.random());
			int oval2 = (int)(70*Math.random());
			p.setColor(Color.red);
			p.drawOval(oval1, oval1, oval1, oval1);
			
			p.drawOval(oval2, oval2, oval2, oval2);
			p.fillOval(oval1, oval1, oval1, oval1);
			p.fillOval(oval2, oval2, oval2, oval2);
			*/
		}
}

public class thirdApplication implements WindowListener {
	private Frame frame;
	private kanvas cerceve;
	
	public thirdApplication() {
		frame = new Frame();
		cerceve = new kanvas();
		frame.addWindowListener(this);
		frame.add(cerceve);
		frame.setSize(1000,700);
		frame.setResizable(false);
		frame.setVisible(true);
	}
	
	public static void main(String[] args) {
		thirdApplication uygulama = new thirdApplication();
	}
	
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
