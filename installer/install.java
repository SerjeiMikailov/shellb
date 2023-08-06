import java.io.IOException;

public class install {
    public static void main(String[] args) {
        try {
            String scriptPath = "./install.sh";
            
            ProcessBuilder processBuilder = new ProcessBuilder("bash", scriptPath);
            
            processBuilder.redirectOutput(ProcessBuilder.Redirect.INHERIT);
            processBuilder.redirectError(ProcessBuilder.Redirect.INHERIT);            
            
            Process process = processBuilder.start();
          
            int exitCode = process.waitFor();
            
            System.out.println("Script executed with exit code: " + exitCode);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
