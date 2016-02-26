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

	private final static byte MAX_COL = 40;
	private final static byte MAX_LIN = 24;
	private final static byte SCREEN_MODE = 0;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		char c = '0';
		
		MSX.screen(SCREEN_MODE);
		MSX.width((byte)MAX_COL);
		MSX.color((byte) 15, (byte) 5, (byte) 5);
		MSX.setCursor(MAX_COL, MAX_LIN);
		MSX.putChar('*');

		for (int i = 1; i <= MAX_COL; i++) 
		{
			MSX.setCursor((byte)i, (byte)2);
			MSX.putChar(c++);
			
			if (c > '9') {c = '0';} 
		}

		c = '0';
		for (int i = 1; i <= MAX_COL; i+=10) 
		{
			MSX.setCursor((byte)i, (byte)1);
			MSX.putChar(c++);
		}

		c = '0';
		for (int i = 1; i <= MAX_LIN; i++) 
		{
			MSX.setCursor((byte)2, (byte)i);
			MSX.putChar(c++);
			
			if (c > '9') {c = '0';} 
		}

		c = '0';
		for (int i = 1; i <= MAX_LIN; i+=10) 
		{
			MSX.setCursor((byte)1, (byte)i);
			MSX.putChar(c++);
		}
		
		c = 'X';
		
		byte lin = 3;
		for (int i = 1; i < 21; i++) 
		{
			MSX.setCursor((byte)i, lin++);
			MSX.putChar(c);
		}

		c = 'Y';
		
		for (int i = 21; i <= MAX_COL; i++) 
		{
			MSX.setCursor((byte)i, lin--);
			MSX.putChar(c);
		}

		while(true);
	}
}
