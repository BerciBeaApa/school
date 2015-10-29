package com.company;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Paul on 28.10.2015.
 */
public class Translator {
    private Dictionary expressionDictionary;

    public Translator() {
        expressionDictionary = new Dictionary("src/resources/expressions.txt");
    }

    public List<String> splitToWords(String rawData) {
        List<String> words = new ArrayList<String>();
        for (String s : rawData.split("\\s")) {
            words.add(s);
        }
        return  words;
    }

    public InternalForm translate(String rawData) {
        InternalForm form = new InternalForm();
        VariableValidator variableValidator = new VariableValidator();
        ConstantsValidator constantsValidator = new ConstantsValidator();
        List<String> words = splitToWords(rawData);
        for(String s : words) {
            if(expressionDictionary.contains(s)) {
                form.addAtoms(s);
                System.out.println("Word " + s + " is atom");
            } else if(variableValidator.validate(s)) {
                form.addVariableSymbols(s);
                System.out.println("Word " + s + " is variable");
            } else if(constantsValidator.validate(s)) {
                form.addConstantSymbols(s);
                System.out.println("Word " + s + " is constant");
            } else {
                System.out.println("Word " + s + " not recognized!");
            }
        }
        return form;
    }

    public void PrintTable(InternalForm form) {

    }
}
