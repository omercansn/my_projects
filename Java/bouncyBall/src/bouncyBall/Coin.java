package bouncyBall;

import java.awt.Graphics;
import java.util.ArrayList;

public class Coin {

    Player ball;
    private final int coinSize = 10;
    private int coinX;
    private int coinY;

    public boolean coinCollected = false;
    public boolean allCoinsCollected = false;
    
    // some getters-setters
    public void setX(int x){
        this.coinX = x;
    }
    public void setY(int y){
        this.coinY = y;
    }
    public int getX(){
        return this.coinX;
    }
    public int getY(){
        return this.coinY;
    }
    public int getCoinSize(){
        return this.coinSize;
    }

    public Coin(int x, int y){
        setX(x);
        setY(y);
    }

    public void drawCoins(Graphics g){
        g.fillOval(coinX, coinY, coinSize, coinSize);
    }

    public static ArrayList<Coin> createCoins(){
        ArrayList<Coin> coins = new ArrayList<>();
        for(int i=0; i<10; i++){
            int x = 50+(int)(900*Math.random());
            int y = 50+(int)(500*Math.random());
            Coin coin = new Coin(x,y);
            coins.add(coin);
        }
        return coins;
    }
    
    public void removeCoin(Player ball, ArrayList<Coin> coins) {
        
        for (Coin coin : coins) {
            if (ball.getX() >= coin.getX() - 20 &&
                ball.getX() <= coin.getX() + coin.getCoinSize() &&
                ball.getY() >= coin.getY() - 20 &&
                ball.getY() <= coin.getY() + coin.getCoinSize()) {
                coins.remove(coin);
                coinCollected = true;
                break; // Remove only one coin per collision
            }
        }
        if(coins.size()==0){
            allCoinsCollected = true;
        }
    }
}
