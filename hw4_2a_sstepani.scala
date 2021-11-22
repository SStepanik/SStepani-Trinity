//By Sean Stepanik, finds the summation of 1/(2n) to the n that the user chooses.
def summation(x:Int):Double = {
        if (x==0){
		0
        }else{
		    summation(x-1) + (1.0/(2*x))
		}
}
 println("Sumation of 1/(2n)")
 print("Enter number of terms to sum: ")
 var term = readInt
 println("The answer is "+summation(term))
