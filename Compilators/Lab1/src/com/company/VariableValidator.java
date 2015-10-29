package com.company;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Paul on 28.10.2015.
 */
public class VariableValidator extends Validator{
    private String wordPattern;

    public  VariableValidator() {
        wordPattern = "^[-+]?[a-zA-Z]+?$";
    }

    public boolean validate(String s) {
        return validatePattern(s, wordPattern);
    }
}
