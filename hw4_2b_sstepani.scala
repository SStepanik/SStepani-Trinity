//By Sean Stepanik, code that makes an hourglass shape out of asterics
def hourGlass(x:Int, y:Int):Unit = {
        if (x > 0){
			println("*"*x)
            hourGlass(x-1, y)
		}else if (x==0){
			hourGlass(x-1, y)
		}else if (x<0 && math.abs(x) != y){
			println("*"*math.abs(x))
            hourGlass(x-1, y)
		}else{
			println("*"*math.abs(x))
		}
}
 print("Enter the number of *s: ")
 var term = readInt
 hourGlass(term, term)