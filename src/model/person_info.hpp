#ifndef PERSON_INFO_HPP
#define PERSON_INFO_HPP


namespace Model
{


enum Gender : int
{
    GENDER_UNKNOWN  = 0,
    GENDER_MALE,
    GENDER_FEMALE,
};


inline QString genderToString(Gender gender)
{
    switch (gender)
    {
    case GENDER_MALE:   return QString("Male");
    case GENDER_FEMALE: return QString("Female");
    default:            return QString("Unknown");
    }
}


class PersonInfo
{
public:

    QString name;
    QString password;
    bool enableOptionalFields = false;
    int age = 30;
    Gender gender = GENDER_UNKNOWN;
    double height = 170.0;
    double weight = 80.0;
    QString notes;
};


} // namespace Model

#endif // PERSON_INFO_HPP
