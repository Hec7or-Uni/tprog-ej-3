# include <iostream>
# include <complex>
# include "Logger.h"
# include "StoreLast.h"
# include "StoreMax.h"
# include "StoreSum.h"
# include "StoreAvg.h"

using namespace std;

int main() {
    Logger<float> temp_log("temperature",
    {
        new StoreLast<float>,
        new StoreMax<float>,
		new StoreSum<float>(0),
        new StoreAvg<float>(0)
    } );
    temp_log.push( 16.0 );
    temp_log.push( {17.5, 25.0, 20.5} );
    temp_log.log();

	cout << endl;

	// NOTA: La clase "StoreMax" no debe estar disponible para números complejos
    Logger<complex<float>> ornt_log("orientation",
	{
		new StoreLast<complex<float>>,
		new StoreAvg<complex<float>>(0),
		new StoreSum<complex<float>>(0)
	} );
	temp_log.push( {0,2.5} );
	ornt_log.push( { {0,1.5}, {3.0}, {2.5,1.0} } );
	ornt_log.log();

    return 0;
}