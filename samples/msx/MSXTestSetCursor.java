/**
 *  Java Grinder
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.naken.cc/
 * License: GPL
 *
 * Copyright 2014-2016 by Michael Kohn
 *
 */

/*
 *   MSX support by Giovanni Nunes - https://github.com/plainspooky
 *                  Emiliano Fraga - https://github.com/efraga-msx
 */

import net.mikekohn.java_grinder.MSX;

/**
 * @author Emiliano
 *
 */
public class MSXTestSetCursor {

	private final static int MAX_COL = 40;
	private final static int MAX_LIN = 24;
	private final static int SCREEN_MODE = 0;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		char c = '0';
		
		MSX.screen(SCREEN_MODE);
		MSX.width(MAX_COL);
		MSX.color(15,5,5);
		MSX.setCursor(MAX_COL, MAX_LIN);
		MSX.putChar('*');

		for (int i = 1; i <= MAX_COL; i++) 
		{
			MSX.setCursor(i,2);
			MSX.putChar(c++);
			
			if (c > '9') {c = '0';} 
		}

		c = '0';
		for (int i = 1; i <= MAX_COL; i+=10) 
		{
			MSX.setCursor(i,1);
			MSX.putChar(c++);
		}

		c = '0';
		for (int i = 1; i <= MAX_LIN; i++) 
		{
			MSX.setCursor(2, i);
			MSX.putChar(c++);
			
			if (c > '9') {c = '0';} 
		}

		c = '0';
		for (int i = 1; i <= MAX_LIN; i+=10) 
		{
			MSX.setCursor(1, i);
			MSX.putChar(c++);
		}
		
		c = 'X';
		
		int lin = 3;
		for (int i = 1; i < 21; i++) 
		{
			MSX.setCursor(i, lin++);
			MSX.putChar(c);
		}

		c = 'Y';
		
		for (int i = 21; i <= MAX_COL; i++) 
		{
			MSX.setCursor(i, lin--);
			MSX.putChar(c);
		}

		while(true);
	}
}
