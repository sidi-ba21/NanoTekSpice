/*
** EPITECH PROJECT, 2022
** Exception
** File description:
** Exception
*/

#include <string>
#include <exception>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class Error: public std::exception
{
    public:
        Error(std::string const &message, std::string const &component = "Unknown");
        virtual const std::string &getComponent() const;
        char const *what() const noexcept;
    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public Error
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
};


#endif /* !EXCEPTION_HPP_ */
