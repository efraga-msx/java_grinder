import net.mikekohn.java_grinder.MSX;

public class MSXgraphics {

	public static void main(String args[]) {

                int pos=0;
                int data=0x68;

		MSX.color(15,1,1);
		MSX.screen(3);
	        for (int i=0; i<1535; i+=2) {
			MSX.writeVRAM(i,0xf8);
			MSX.writeVRAM(i+1,0x8f);
		}
	}
}
