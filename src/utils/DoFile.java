package utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class DoFile {

	public synchronized static void save(String file, String content, boolean add)
			throws IOException {

		FileWriter fw = new FileWriter(file, add);

		fw.write(content);
		fw.close();
	}

	public synchronized static String read(String filename) throws IOException {
		BufferedReader inputStream = new BufferedReader(new FileReader(filename));
		StringBuilder file = new StringBuilder();
		String linha;
		while ((linha = inputStream.readLine()) != null) {
			file.append(linha);
			
		}
		inputStream.close();
		return file.toString(); 
	}
}
