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
	void initFormula( string f )
	{
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

   void printFormula(){
       cout<<"("<<coefficient2<<")"<<"x^2+("<<coefficient1<<")x"<<"+("<<algebraic_coefficient<<")"<<endl;
   }
private:
			char arr[50];
		int coefficient1, coefficient2, algebraic_coefficient;
	};