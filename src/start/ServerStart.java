package start;

import java.io.IOException;

import server.HttpServer;
import java.net.*;

public class ServerStart {

	public static void main(String[] args) throws IOException {
		ServerSocket server = new ServerSocket(8001);
		while(true){
			Socket client = server.accept();
			Thread t1 = new Thread(new HttpServer(client));
			t1.start();
			System.out.println("trhead");
		}
	}

}
