#include <iostream>
#include <mysql/mysql.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>

std::map<std::string, std::string> readEnvFile(const std::string &fileName) {
    std::map<std::string, std::string> envMap;
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                envMap[key] = value;
            }
        }
        file.close();
    }
    return envMap;
}

int main()
{
    // geting
    std::map<std::string, std::string> env = readEnvFile(".env");


    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    const char* user = env["user"].c_str();
    const  char* password = env["password"].c_str();
    std::cout << user << "\n";
    std::cout << password << "\n";
    if (!mysql_real_connect(conn, "127.0.0.1", user, password, "test", 3306, NULL, 0))
    {
        std::cout << "Error connecting to database: " << mysql_error(conn) << std::endl;
        return 1;
    }
    std::cout << "hola" << "\n";
    if (mysql_query(conn, "SELECT name, age FROM USERS"))
    {
        std::cout << "Error executing query: " << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res)))
    {
        std::cout << row[0] << " " << row[1] << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
