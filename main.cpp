#include <iostream>
#include <mysql.h>

using namespace std;

class Connection{

    const char* HOSTNAME;
    const char* DATABASE;
    const char* USERNAME;
    const char* PASSWORD;
    const char* SOCKET;
    const int PORT = 3306;
    const int OPT = 0;

    MYSQL *CONN;
    MYSQL_RES *RES;
    MYSQL_ROW ROW;

public:
    Connection();
    bool ejecucion();

};

Connection::Connection() {

    HOSTNAME = "localhost";
    DATABASE = "pruebac++";
    USERNAME = "root";
    PASSWORD = "jerssondb";
    SOCKET = NULL;

}

bool Connection::ejecucion(){

    try{

        CONN = mysql_init(NULL);

        if (!mysql_real_connect(CONN,HOSTNAME,USERNAME,PASSWORD,DATABASE,PORT,SOCKET,0)){
            cerr << mysql_error(CONN) << endl;
            return false;
        }

        if (mysql_query(CONN,"SHOW TABLES")){
            cerr << mysql_error(CONN) << endl;
            return false;
        }

        RES = mysql_use_result(CONN);

        cout << "*** MYSQL - SHOW TABLES *** => "<< DATABASE <<endl;

        while ((ROW = mysql_fetch_row(RES)) != NULL)
            cout << ROW[0] <<endl;

        mysql_free_result(RES);

        mysql_close(CONN);

        return true;


    } catch(char *e){
        cerr << "[EXECPTION] " << e << endl;
        return false;
    }

}

int main()
{
    try{

        Connection objConn;
        bool result = objConn.ejecucion();
        if (!result) cout << "ERROR!!!!" <<endl;

    } catch (char *e){
        cerr << "[EXECPTION] " << e << endl;
    }

    return 0;
}
