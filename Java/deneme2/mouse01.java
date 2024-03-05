package deneme2;

import java.awt.*;
import java.awt.event.*;

class kanvas01 extends Canvas implements MouseListener, MouseMotionListener
{
	private Point m;
	private int x = 300;
	private int y = 175;
	Point center = new Point(300+200/2,175+200/2);
	double radius = 100.;
	boolean isDragged = false;
	public kanvas01()
	{
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	
	public static double getDistance(Point p1, Point p2) {
		return(Math.sqrt(Math.pow(p1.x-p2.x,2)+Math.pow(p1.y-p2.y,2)));
	}
	public void paint(Graphics p)
	{
		if (m==null) {
			p.setColor(Color.black);
			setBackground(Color.black);	
		}
		else {
			p.setColor(Color.white);
			setBackground(Color.yellow);
		}
		
		
		p.fillOval(x, y, 200, 200);
		//p.drawRect(300, 175, 200, 200);
		p.setColor(Color.black);
		p.drawString("("+m.x+" , "+m.y+")",m.x, m.y);
	}
	
	public void mouseMoved(MouseEvent e)
	{ 	
	 	m=e.getPoint();	
	 	repaint();	
	}
	
	public void mousePressed(MouseEvent e){
		if(getDistance(center,m)<radius) {
			isDragged = true;
		}
	}
	public void mouseDragged(MouseEvent e) {
		if(isDragged) {
			int distanceX = e.getX()-m.x;
			int distanceY = e.getY()-m.y;
			center.x+=distanceX;
			center.y+=distanceY;
			x += distanceX;
			y += distanceY;
		}
		m=e.getPoint();	
	 	repaint();
	}
	public void mouseReleased(MouseEvent e) {
		isDragged = false;
	}
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
}

public class mouse01 implements WindowListener
{
	private Frame a;
	private kanvas01 k;

	public mouse01()
	{
		a = new Frame();
		k = new kanvas01();
		a.addWindowListener(this);
		a.add(k);
		a.setSize(800,600);
		a.setResizable(false);
		a.setVisible(true);
	}
	
	public static void main(String args[])
	{
		mouse01 uygulama = new mouse01();
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

