class IdDuplicateException: public exception{
public:
    char * what () {
        return "The id is already in use";
    }
};

class IdOutOfRangeException: public exception{
public:
    char * what () {
        return "The id is out of range";
    }
};

class InvalidArgumentsException: public exception{
public:
    char * what () {
        return "The Arguments are not correct";
    }
};

class NonExistendProduktException: public exception{
public:
    char * what () {
        return "There is no product with such id";
    }
};
