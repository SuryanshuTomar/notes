const path = require('path');
const TerserPlugin = require('terser-webpack-plugin');
var webpack = require('webpack');
const nodeExternals = require('webpack-node-externals');

var config = {
  mode: 'production',
  //devtool: 'inline-source-map',
  entry: {
    entry: './src/index.js'
  },
  output: {
    path: path.resolve(__dirname, 'build'),
    filename: 'index.js',
    libraryTarget: 'commonjs2'
  },
  optimization: {
    minimizer: [new TerserPlugin({extractComments: false})],
  },
  module: {
    rules: [{
      test: /\.(js|jsx)$/,
      exclude: /node_modules/,
      use: {
        loader: 'babel-loader'
      }
    }, {
      test: /\.css$/,
      use: {
        loader: 'style-loader!css-loader'
      }
    },
    {
      test: /\.(png|jpg|gif)$/,
      use: [{
        loader: 'file-loader'
      }]
    }
    ]
  },
  resolve: {
    extensions: ['.js', '.jsx'],
    alias: {
      react: path.resolve('./node_modules/react')
    }
  },
  plugins:[
    new webpack.DefinePlugin({
    })
  ],
  externals: [
    nodeExternals(),
    {
      'react': {
        root: 'React',
        commonjs2: 'react',
        commonjs: 'react',
        amd: 'react'
      },
      'react-dom': {
        root: 'ReactDOM',
        commonjs2: 'react-dom',
        commonjs: 'react-dom',
        amd: 'react-dom'
      },
      '@license-admin/ajaxhelper': {
        root: '@license-admin/ajaxhelper',
        commonjs2: '@license-admin/ajaxhelper',
        commonjs: '@license-admin/ajaxhelper',
        amd: '@license-admin/ajaxhelper'
      },
      '@license-admin/helper': {
        root: '@license-admin/helper',
        commonjs2: '@license-admin/helper',
        commonjs: '@license-admin/helper',
        amd: '@license-admin/helper'
      }
    }
  ]
};
module.exports = config;