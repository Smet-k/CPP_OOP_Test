#ifndef ILogger_h
#define ILogger_h

#include "DateTime.h"


class ILogger
{
public:

    List<const char*> logs;
    virtual void Log(const char* value) = 0;
    virtual const char* GetStackTrace() = 0;
    virtual char* ToString() = 0;
};



class ConsoleLogger : public ILogger
{
public:
    
   

    void Log(const char* value)
    {
        DateTime date = DateTime::now();
        char* stringDate = new char[128];
        strcpy(stringDate, "[");
        stringDate = strcat(stringDate, date.toString());
        stringDate = strcat(stringDate, "] - ");
        value = strcat(stringDate, value);
        logs.add(value);
    }


    char* ToString()
    {
        char* output = new char[256];
        if (logs.length() > 0)
        {
            strcpy(output, logs[0]);
        }
        else
        {
            strcpy(output, "");
            return output;
        }
        output = strcat(output, "\n");
        for (int i = 1; i < logs.length(); i++)
        {
            output = strcat(output, logs[i]);
            output = strcat(output, "\n");
        }
        return output;
    }

    const char* GetStackTrace()
    {
        return StaticPath::path.ToString();
    }

    class StaticPath
    {
    public:
        static ConsoleLogger path;
    };

};




#endif