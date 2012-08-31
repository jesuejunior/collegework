package start;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;

import utils.Helper;

class HttpServer {
	public static void main(String[] args) throws IOException {
		Helper helper = new Helper();
		String clientData;
		ServerSocket welcomeSocket = new ServerSocket(8001);
		final String END_LINE = "\r\n";

		
		while (true) {
			Socket connectionSocket = welcomeSocket.accept();
			BufferedReader clientIn = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
			DataOutputStream clientOut = new DataOutputStream(connectionSocket.getOutputStream());
			clientData = clientIn.readLine();
			
			if (clientData != null && clientData.startsWith("GET")) {
				ArrayList<String> broken = smash(clientData);
				if(broken.get(1).equals("/")){
					clientOut.writeBytes(helper.response("http200"));
					clientOut.writeBytes(helper.response("server"));
					clientOut.writeBytes("Date: " + helper.getServerTime());
					clientOut.writeBytes("Content-Length: " + clientOut.size());
					connectionSocket.close();
				}else{
					clientOut.writeBytes(helper.response("http404"));
				}
			} else if (clientData != null && clientData.startsWith("POST")) {
				
			}
			
		}
		
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
