package msft3c;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class FindMissingNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner inFile = new Scanner(new FileReader("PracticeInput.txt"));
			PrintWriter outFile = new PrintWriter("PracticeOutput.txt");
			
			int numOfLine = inFile.nextInt();
			String[] numString = new String[numOfLine];
			
			inFile.nextLine();
			for (int i=0; i<numOfLine; i++) {
				numString[i] = inFile.nextLine();
				String[] tokenArray = numString[i].split(" ");

				int[] numArray = new int[tokenArray.length];
				
				for (int j=0; j<tokenArray.length; j++) {
					numArray[j] = Integer.parseInt(tokenArray[j]);
				}

				Arrays.sort(numArray);
				
				int currentNum;
				int nextNum;
				int diff;
				String result = "";

				for (int j=0; j<numArray.length-1; j++){
					currentNum = numArray[j];
					nextNum = numArray[j+1];
					diff = nextNum - currentNum;
					if (diff > 1) {
						for (int k=1; k<diff; k++) {
							result = result + (Integer.toString(currentNum + k) + " ");
						}
					}
				}
				
				outFile.println(result.trim());
			}
			
			inFile.close();
			outFile.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
