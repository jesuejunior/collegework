package start;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.HashMap;

import utils.Helper;

class HttpServer {
	public static void main(String[] args) throws IOException {
		Helper helper = new Helper();
		String clientData;
		String path = null;
		String protocol = null;
		String call = null;
		ServerSocket welcomeSocket = new ServerSocket(8001);

		while (true) {
			Socket connectionSocket = welcomeSocket.accept();
			BufferedReader clientIn = new BufferedReader(new InputStreamReader(	connectionSocket.getInputStream()));
			DataOutputStream clientOut = new DataOutputStream(connectionSocket.getOutputStream());
			clientData = clientIn.readLine();
			//clientOut.size();
			if (clientData != null && clientData.startsWith("GET")) {
				System.out.println(clientData);
				ArrayList<String> broken = smash(clientData);
				if(broken.get(1).equals("/")){
					System.out.println(broken.get(1));
					clientOut.writeBytes(helper.response("http200"));
					welcomeSocket.close();
				}else{
					clientOut.writeBytes(helper.response("http404"));
				}
				
			} else if (clientData != null && clientData.startsWith("POST")) {
				System.out.println(clientData);
			}
			
		System.out.println("falhou");
		}
		// welcomeSocket.close();

		// if(){
		// }
	}

	public static ArrayList<String> smash(String input) {
		ArrayList<String> list = new ArrayList<String>();
		String[] a = input.split(" ");
		for (String r : a) {
			list.add(r);
		}

		return list;
	}

}
