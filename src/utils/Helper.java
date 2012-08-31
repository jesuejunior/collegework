package utils;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Locale;
import java.util.TimeZone;

public class Helper {
	private static final HashMap<String, String> MAP_RESPONSE = new HashMap<String, String>();
	static {
		MAP_RESPONSE.put("GET", "GET" + "\r\n");
		MAP_RESPONSE.put("server", "Server: SocketHard by Jesue Junior" + "\r\n");
		MAP_RESPONSE.put("http200", "HTTP/1.1 200 OK" + "\r\n");
		MAP_RESPONSE.put("http404", "HTTP/1.1 404 Not Found" + "\r\n");
	}

	public String response(String s){
		for (String k: MAP_RESPONSE.keySet()){
			s = s.replaceAll(k, MAP_RESPONSE.get(k));
		}
		return s;
	}
	public String getServerTime() {
	    Calendar calendar = Calendar.getInstance();
	    SimpleDateFormat dateFormat = new SimpleDateFormat(
	        "EEE, dd MMM yyyy HH:mm:ss z", Locale.US);
	    dateFormat.setTimeZone(TimeZone.getTimeZone("GMT"));
	    return dateFormat.format(calendar.getTime());
	}
}


