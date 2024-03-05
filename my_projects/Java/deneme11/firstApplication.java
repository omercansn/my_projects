package deneme11;

import java.awt.*;
import java.awt.event.*;

public class firstApplication implements WindowListener, ActionListener
{
	private Frame a;
	private Panel b;
	private Label c,e,bottom;
	private TextField in1,in2;
	private Button d,f,h;
	double Currency = 30.89;
	public firstApplication()
	{
		
		a = new Frame();
		b = new Panel();
		c = new Label("TL: ");
		b.add(c);
		in1 = new TextField(20);
		b.add(in1);
		d = new Button("USD'ye cevir");
		b.add(d);
		e = new Label("USD: ");
		b.add(e);
		in2 = new TextField(20);
		b.add(in2);
		
		f = new Button("TL'ye cevir");
		b.add(f);
		h = new Button("Exit");
		b.add(h);
		
		bottom = new Label("1$ = " + (Currency==(int)(Currency)?(int)Currency:Currency) + "₺");
		b.setLayout(new FlowLayout(FlowLayout.LEADING,5,15));
		b.add(bottom);
		b.setBackground(Color.yellow);
		a.add(b);
		d.addActionListener(this);
		f.addActionListener(this);
		h.addActionListener(this);
		a.addWindowListener(this);
		a.pack();
		
		
		a.setSize(350,200);
		a.setResizable(false);
		a.setVisible(true);
	} 
	
	public static void main(String args[])
	{
		firstApplication uygulama = new firstApplication();
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==h) {
			System.exit(0);
		}
		double USDValue, TLValue;
		String USD, TL;
		String text1=in1.getText();
		String text2=in2.getText();
		try {
			if(e.getSource()==d) {
				if (Double.parseDouble(text1)>=0){
					TLValue = Double.parseDouble(text1);
					USDValue = TLValue/Currency;
					USD = String.valueOf(USDValue);
					in2.setText(USD);
				} else {
					in2.setText("NegativeError");
				}
				
			}
			if(e.getSource()==f) {
				if (Double.parseDouble(text2)>=0) {
					USDValue = Double.parseDouble(text2);
					TLValue = USDValue*Currency;
					TL = String.valueOf(TLValue);
					in1.setText(TL);
				} else {
					in1.setText("NegativeError");
				}
				
			}
		}

		catch(Exception err) {
			Frame error= new Frame();
			Panel er = new Panel();
			Label l = new Label("ERROR!!! You should've entered ONLY numbers!");
			er.add(l);
			er.setBackground(Color.red);
			error.add(er);
			error.addWindowListener(this);
			error.pack();
			error.setSize(450,150);
			error.setResizable(false);
			error.setVisible(true);
		}
   
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

