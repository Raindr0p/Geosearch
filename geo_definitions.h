class point {
public:
    
	void initPoint( double x_value, double y_value )
	{
		x	= x_value;
		y	= y_value;
	};
	void printPointPos()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}


private:
	double x, y;
};

class line {
public:
	void initLine()
	{
	}


private:
};

class formula {
public:
	void initFormula( string f ){
        power=2;
		f.append( "#" );
		strcpy( arr, f.c_str() );
		if ( arr[0] == 'y' && arr[1] == '=' )
		{
			for ( int i = 0; i < 49; i++ )
			{
				if ( arr[i] == 'x' && arr[i + 1] == '^' && arr[i + 2] == '2' )
				{
					if ( arr[i - 1] == '=' )
						coefficient2 = 1;
					else
						if ( arr[i - 1] == '-' )
							coefficient2 = -1;
						else if( arr[i-2]=='-')
                        coefficient2 = -atoi(&arr[i - 1]);
                    else coefficient2 = atoi(&arr[i - 1]);
                        
					
				}


				if ( arr[i] == 'x' && arr[i + 1] != '^' )
				{
					if ( arr[i - 1] == '+' )
						coefficient1 = 1;
					else if ( arr[i - 1] == '-' )
						coefficient1 = -1;
					else if( arr[i-2]=='-')
                        coefficient1 = -atoi(&arr[i - 1]);
                    else coefficient1 = atoi(&arr[i - 1]);
				}

				if ( arr[i] == '#' ){
                  if( arr[i-2]=='-')
                        algebraic_coefficient = -atoi(&arr[i -1]);
                    else algebraic_coefficient = atoi(&arr[i-1]);
                }
					
			}
		}     else cout << "The formula can not be initialized.";
	}
    void initFormula(double c2,double c1,double ac){
        power=2;
        coefficient1=c1;
        coefficient2=c2;
        algebraic_coefficient=ac;
    }
    void initFormula(double cinverse){
       power=-1;
       inverse_coffcient=cinverse;
    }
   void printFormula(){
       if(power==-1)
       cout<<"("<<inverse_coffcient<<")x^-1"<<endl;
       else
       cout<<"("<<coefficient2<<")"<<"x^2+("<<coefficient1<<")x"<<"+("<<algebraic_coefficient<<")"<<endl;
   }
private:
			char arr[50];
		double coefficient1, coefficient2, algebraic_coefficient,power,inverse_coffcient;
	};