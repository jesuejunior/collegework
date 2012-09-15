package server;

import java.io.*;
import java.net.*;
import java.util.ArrayList;

import utils.DoFile;
import utils.Helper;

public class HttpServer implements Runnable {

	Helper helper = new Helper();
	String clientData;
	Socket connectionSocket;
	final String END_LINE = "\r\n";
	String index;

	public HttpServer(Socket p) throws IOException {
		connectionSocket = p;
	}

	public void run() {
		try {
			index = DoFile.read("static/index.html");
		} catch (IOException e) {
			e.printStackTrace();
		}
		String notFound = null;
		try {
			notFound = DoFile.read("static/404.html");
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			BufferedReader clientIn = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
			DataOutputStream clientOut = new DataOutputStream(connectionSocket.getOutputStream());
			clientData = clientIn.readLine();

			if (clientData != null && (clientData.startsWith("GET") || clientData.startsWith("POST"))) {
				ArrayList<String> broken = smash(clientData);
				if (broken.get(1).equals("/") || broken.get(1).equals("/index.html") || broken.get(1).equals("index.html")) {
					if (broken.get(2).equals("HTTP/1.0")) {
						clientOut.writeBytes(END_LINE);
						clientOut.writeBytes(helper.response("http0200"));
					}
					clientOut.writeBytes(END_LINE);
					clientOut.writeBytes(helper.response("http1200"));
					clientOut.writeBytes(helper.response("server"));
					clientOut.writeBytes("Date: " + helper.getServerTime() + END_LINE);
					if (broken.get(2).equals("HTTP/1.0")) {
						clientOut.writeBytes("Connection: close" + END_LINE);
					}
					clientOut.writeBytes("Content-Length: "	+ clientOut.size() + END_LINE);
					clientOut.writeBytes(END_LINE);
					clientOut.writeBytes(END_LINE);
					clientOut.writeBytes(index);
					connectionSocket.close();
				} else {
					clientOut.writeBytes(helper.response("http404"));
					clientOut.writeBytes(notFound);
					connectionSocket.close();
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
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
