package com.company;

/**
 * Created by Paul on 28.10.2015.
 */
public class Application {
    private String fileData;
    private InternalForm form;
    private Translator translator;

    public Application() {
    }


    public void Run() {
        FileManager fm = new FileManager("src/resources/input2.txt");
        fileData = fm.readFromFile();
        fileData = fileData.replaceAll("\\s+", " ");
        translator = new Translator();
        form = translator.translate(fileData);
        System.out.println(form.internalFormString());
    }
}
