public class AddDigits {
	public int addDigits(int num) {
        int remainder = 0;
        int quotient = 0;
        while(num >= 10){
            remainder = num % 10;
            quotient = num / 10;
            num = remainder + quotient;
        }
        return num;
    }
}

