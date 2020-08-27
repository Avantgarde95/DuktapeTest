const path = require('path');
const {CleanWebpackPlugin} = require('clean-webpack-plugin');

function getAbsolutePath(...paths) {
    return path.resolve(__dirname, ...paths);
}

module.exports = (env, argv) => {
    const isDebugMode = !argv || argv.mode === 'development';
    const srcDir = 'src/app';
    const outDir = 'dist';

    return {
        mode: 'development',
        entry: getAbsolutePath(srcDir, 'Main.ts'),
        devtool: isDebugMode ? 'inline-source-map' : false,
        output: {
            path: getAbsolutePath(outDir),
            publicPath: outDir + '/',
            filename: 'bundle.js'
        },
        resolve: {
            extensions: [
                '.ts', '.tsx', '.js',
                '.png', '.jpg', '.svg'
            ]
        },
        module: {
            rules: [
                {
                    test: /\.tsx?$/,
                    use: {loader: 'ts-loader'}
                }
            ]
        },
        plugins: [
            new CleanWebpackPlugin()
        ]
    };
};
