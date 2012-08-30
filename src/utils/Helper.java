package utils;

import java.util.HashMap;

public class Helper {
	private static final HashMap<String, String> MAP_RESPONSE = new HashMap<String, String>();
	static {
		MAP_RESPONSE.put("GET", "GET");
		MAP_RESPONSE.put("server", " Server: SocketHard by Jesué Junior");
		MAP_RESPONSE.put("http200", "HTTP/1.1 200 OK");
		MAP_RESPONSE.put("http404", "HTTP/1.1 404 Not Found");
	}

	public String response(String s){
		for (String k: MAP_RESPONSE.keySet()){
			s = s.replaceAll(k, MAP_RESPONSE.get(k));
		}
		return s;
	}
}


