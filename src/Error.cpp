/*
** EPITECH PROJECT, 2022
** Error
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

std::string const &Error::getComponent() const
{
    return _component;
}

char const *Error::what() const noexcept
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
: Error(message, component)
{
}
