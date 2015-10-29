package com.company;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Paul on 28.10.2015.
 */
public class ConstantsValidator extends Validator {
    private String pattern;

    public  ConstantsValidator() {
        pattern = "^[-+]?\\d+(\\.\\d+)?$";
    }

    public boolean validate(String s) {
        return validatePattern(s, pattern);
    }
}
