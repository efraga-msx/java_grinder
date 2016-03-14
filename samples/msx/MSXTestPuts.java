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

public class MSXTestPuts {
	public static String strMsg = "Hello MSX from JAVA";

	public static void main(String args[]) {
		short[] aC = new short [strMsg.length()];
		int scrMode = 0;
		int lin, col;
		
		for (int i = 0; i < strMsg.length(); i++) {
			aC[i] = (short) strMsg.charAt(i);
		}
		
		lin = 10;
		col = 20;
		
		MSX.screen(scrMode);

		MSX.setCursor(col, lin);

		for (int i = 0; i < aC.length; i++) {
			MSX.putChar((char)aC[i]);
		}
		
//		MSX.putS(strMsg.length(), aC);

		while (true);
	}
}
