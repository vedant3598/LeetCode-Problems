import java.util.*;
public class HeightChecker {
	public int heightChecker(int[] heights) {
        int[] array = new int[heights.length];
        int studentsNum = 0;
        
        for(int i = 0; i < heights.length; i++){
            array[i] = heights[i];
        }
        
        Arrays.sort(array);
        
        for(int i = 0; i < heights.length; i++){
            if(array[i] != heights[i])
                studentsNum++;
        }
        return studentsNum;
    }
}
