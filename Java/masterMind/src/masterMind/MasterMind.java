package masterMind;

import java.awt.Button;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.Action;
import javax.swing.JFrame;
import javax.swing.JPanel;

class GamePanel extends JPanel implements ActionListener{
	
	private TextField text1 = new TextField(10);
	private TextField text2 = new TextField(30);
	private Button ok = new Button("OK");
	private Button exit = new Button("Exit");
	Button playAgain = new Button("Play Again");
	private Label label1,label2;
	private int[] digits = {0,1,2,3,4,5,6,7,8,9};
	private int numberToGuess = generateRandomNumber();
	private int guessAmount = 0;
	private boolean success = false;
	
	public GamePanel() {
		setBackground(Color.cyan);
		label1 = new Label("Insert a 4-digit number:");
		add(label1);
		add(text1);
		add(ok);
		ok.addActionListener(this);
		add(exit);
		exit.addActionListener(this);
		setLayout(new FlowLayout(FlowLayout.LEFT,5,5));
		label2 = new Label("Result:");
		add(label2);
		add(text2);
	}
	
	public int generateRandomNumber(){
		int number;
		do{
			number = (int)(9876*Math.random());
		} while(thereIsDuplication(number) || number < 1234);
		return number;
	}
	
	public boolean thereIsDuplication(int num){
		String numStr = Integer.toString(num);
		for (int i = 0; i < numStr.length(); i++) {
			char currentChar = numStr.charAt(i);
			for (int j = i + 1; j < numStr.length(); j++) {
				if (currentChar == numStr.charAt(j)) {
					return true; // Found a duplicate
				}
			}
		}
		return false; // No duplicates found
	}
	
	public void createErrorWindow() {
		WindowListener wl = null;
		JFrame error= new JFrame("ERROR!");
		JPanel p = new JPanel();
		Label l = new Label("You must enter a number whose digits are different from each other between 1234 and 9876!");
		p.add(l);
		p.setBackground(Color.red);
		error.add(p);
		error.addWindowListener(wl);
		error.pack();
		error.setSize(600,150);
		error.setLocationRelativeTo(null);
		error.setResizable(false);
		error.setVisible(true);
	}

	public void createSuccessWindow() {
		WindowListener wl = null;
		ActionListener al = null;
		JFrame suc= new JFrame("SUCCESS!");
		JPanel p = new JPanel();
		Label l = new Label("Congrats! You found it in " + guessAmount + " attempts!");
		p.add(l);
		/* 
		p.add(playAgain);
		playAgain.addActionListener(al);
		*/
		
		p.setBackground(Color.green);
		suc.add(p);
		suc.addWindowListener(wl);
		suc.pack();
		suc.setSize(300,150);
		suc.setLocationRelativeTo(null);
		suc.setResizable(false);
		suc.setVisible(true);
	}
	
	//some ActionListener stuff
	public void actionPerformed(ActionEvent e) {
		
		try{
			if(e.getSource()==exit) {
				System.exit(0);
			}

			String numberToGuessStr = Integer.toString(numberToGuess);
			String numberToEnterStr = text1.getText();

			int numberToEnter = Integer.parseInt(numberToEnterStr);

			if((numberToEnter < 1234 || numberToEnter > 9876)){
				throw new Exception();
			}
			if(e.getSource()==ok) {
				if(numberToEnterStr==null){
					throw new Exception();
				}
				System.out.println(numberToGuess);
				guessAmount++;
				if(thereIsDuplication(numberToEnter)){
					createErrorWindow();
				} else {
					int plus = 0;
					int minus = 0;
					char[] digitsGuess = new char[4];
					char[] digitsEnter = new char[4];
					for (int i = 0; i < numberToEnterStr.length(); i++) {
						digitsGuess[i] = numberToGuessStr.charAt(i);
						digitsEnter[i] = numberToEnterStr.charAt(i);
						if (numberToEnterStr.charAt(i) == numberToGuessStr.charAt(i)) {
							plus++;
						} else {
							for(int j = 0; j < numberToEnterStr.length(); j++){
								if(numberToEnterStr.charAt(i) == numberToGuessStr.charAt(j)){
									minus++;
								}
							}
						}
					}
					if(plus == 4){
						success = true;
					}
					if(success){
						createSuccessWindow();
					} else {
						text2.setText("+" + plus + " -" + minus);
					}
				}
			}
			if(e.getSource()==playAgain){
				success = false;
				generateRandomNumber();
			}
		} catch (Exception err){
			createErrorWindow();
		}
		
	}
	
}

public class MasterMind implements WindowListener{
	
	public final int screenWidth = 360;
	public final int screenHeight = 240;
	JFrame frame = new JFrame("MasterMind Game");
	GamePanel panel = new GamePanel();

	public MasterMind() {
		frame.addWindowListener(this);
		frame.add(panel);
		frame.setSize(screenWidth,screenHeight);
		frame.setLocationRelativeTo(null);
		frame.setResizable(false);
		frame.setVisible(true);
	}
	
	
	public static void main(String[] args) {
		MasterMind game = new MasterMind();
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
